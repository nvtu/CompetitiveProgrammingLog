#include <bits/stdc++.h>
using namespace std;
const int SZ = int(3e5+5);

int n;
// f[i][j][k] is the maximum sum till point i with length j and considering taking the current node by the value of k
long long A[SZ], f[SZ][5][2];
int trace[SZ][5][2];
vector<int> edge[SZ];
bool visited[SZ];


void compute(int u, int parent) {
    f[u][0][1] = A[u];
    trace[u][0][1] = A[u];
    for (int i=1; i<5; i++) {
        // Update the value if current node is not chosen
        int j = 1, k = i - 1;
        if (f[parent][i][0] > f[parent][i-1][1]) j = 1 - j, k = i;
        else if (f[parent][i][0] == f[parent][i-1][1]) {
            if (trace[parent][i][0] < trace[parent][i-1][1]) j = 1 - j, k = i;
        }
        f[u][i][0] = f[parent][k][j];
        trace[u][i][0] = trace[parent][k][j];
      
        if (i < 4) {
            // Update the value if current node is chosen
            int MAX = max(trace[parent][i][0], trace[parent][i-1][1]);
            int MIN = min(trace[parent][i][0], trace[parent][i-1][1]);
            if (A[u] >= MAX) { // Current value is a good fit for both cases
                if (MAX == 0) continue;
                if (A[u] > MAX) {
                    f[u][i][1] = max(f[parent][i][0], f[parent][i-1][1]) + A[u];
                }
                else if (A[u] == MAX) {
                    j = 1, k = i - 1;
                    if (trace[parent][i-1][1] == MAX) j = 1 - j, k = i;
                    if (trace[parent][k][j] == MAX || trace[parent][k][j] == 0) continue;
                    f[u][i][1] = f[parent][k][j] + A[u];  
                }
                trace[u][i][1] = A[u];
            }
            else if (A[u] >= MIN) { // Current value fit at least one case: MAX > A[u] >= MIN
                if (A[u] == MIN || MIN == 0) continue;
                j = 1, k = i - 1;
                if (trace[parent][i][0] < trace[parent][i-1][1]) j = 1 - j, k = i;
                else if (trace[parent][i][0] == trace[parent][i-1][1]) {
                    if (f[parent][i][0] > f[parent][i-1][1]) j = 1 - j, k = i;
                }
                f[u][i][1] = f[parent][k][j] + A[u];
                trace[u][i][1] = A[u];
            }
        }
    }
}


void dfs(int u, int parent) {
    visited[u] = true;
    compute(u, parent);
    for (auto v: edge[u]) {
        if (visited[v] == false) 
            dfs(v, u);
    }
}


int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++) cin >> A[i];
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    memset(f, 0LL, sizeof(f)); 
    memset(trace, 0, sizeof(trace));
    dfs(1, 0);
    long long ans = 0;
    for (int i=1; i<=n; i++) {
        ans = max(ans, max(f[i][4][0], f[i][3][1]));
    }
    cout << ans << endl;
    return 0;
}

