#include <bits/stdc++.h>
using namespace std;
const int SZ = int(1e5+5);

int N, a;
long long val[SZ];
vector<int> edges[SZ];
bool visited[SZ];
long long ans = 0;


int dfs(int u) {
    visited[u] = true;
    long long old = val[u];
    for (auto v: edges[u]) {
        if (visited[v] == false) 
            val[u] ^= dfs(v);
    }
    // Count bit 1
    while (val[u] > 0) {
        if (val[u] & 1) ans++;
        val[u] >>= 1;
    }
    cout << ans << endl;
    return old;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> a;

    memset(visited, false, sizeof(visited));
    for (int i=0; i<N-1; i++) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    for (int i=1; i<=N; i++) cin >> val[i];
    dfs(a); 
    cout << ans << endl;
    return 0;
}

