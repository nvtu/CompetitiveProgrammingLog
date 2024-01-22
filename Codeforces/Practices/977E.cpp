#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstdlib>
#include <set>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(2e5+5);
const long long MOD = int(1e9+7);
const double EPS = 1e-6;

int n, m, dsu[MAX_SIZE], sz[MAX_SIZE], deg[MAX_SIZE];
vector<int> edge[MAX_SIZE];
vector<int> dsuC[MAX_SIZE];

void initialize() {
    for (int i=1; i<n+1; i++) {
        dsu[i] = i;
        sz[i] = 1;
    }
}

int findRoot(int dsu[], int u) {
    if (dsu[u] == u) return u;
    return dsu[u] = findRoot(dsu, dsu[u]);
}

void unionV(int dsu[], int N, int u, int v) {
    int rootU = findRoot(dsu, u);
    int rootV = findRoot(dsu, v);
    if (rootU == rootV) return;
    if (sz[rootU] > sz[rootV]) swap(rootU, rootV);
    dsu[rootU] = rootV;
    sz[rootV] += sz[rootU];
}


void solve() {
    cin >> n >> m;
    memset(deg, 0, sizeof(deg));
    initialize();
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        unionV(dsu, n, u, v);
        deg[u]++;
        deg[v]++;
    }
    int ans = 0;
    for (int i=1; i<n+1; i++) {
        int root = findRoot(dsu, i);
        dsuC[root].push_back(i);
    }
    for (int i=1; i<n+1; i++) {
        if (dsu[i] == i) {
            bool isCyclic = true;
            for (int j=0; j<dsuC[i].size(); j++) {
                int u = dsuC[i][j];
                if (deg[u] != 2) isCyclic = false;
            }
            if (isCyclic) ans++;
        }
    }
    cout << ans << endl;
}


int main() {
    // freopen("inp.txt", "r", stdin);

    //Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}