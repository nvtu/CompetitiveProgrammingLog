#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, m, u, v;
long long ans = LLONG_MAX;

void dfs(vector<int> edges[], vector<bool>& visited, vector<int>& sz, vector<int>& low, vector<int>& disc, int u, int parent, int& time, vector<pair<int, int> >& bridges) {
    visited[u] = true;
    disc[u] = low[u] = ++time;
    for (auto v : edges[u]) {
        if (!visited[v]) {
            dfs(edges, visited, sz, low, disc, v, u, time, bridges);
            low[u] = min(low[u], low[v]);
            sz[u] += sz[v];
        } else if (v != parent) {
            low[u] = min(low[u], disc[v]);
        }
    }
    if (low[u] > disc[parent]) {
        bridges.push_back({min(u, parent), max(u, parent)});
        ans = min(ans, 1LL * sz[u] * (sz[u] - 1) / 2 + 1LL * (n - sz[u]) * (n - sz[u] - 1) / 2);
    }
}

vector<pair<int, int> > findBridges(vector<int> edges[], int V) {
    vector<pair<int, int> > bridges;
    vector<bool> visited(V + 1, false);
    vector<int> low(V + 1, INT_MAX);
    vector<int> disc(V + 1, 0);
    vector<int> sz(V + 1, 1);  // size of subtree rooted at i (1-based index)
    int time = 0;
    int parent = -1;
    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            dfs(edges, visited, sz, low, disc, i, parent, time, bridges);
        }
    }
    return bridges;
}

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> edges[n + 1];
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        ans = 1LL * n * (n - 1) / 2;
        vector<pair<int, int> > bridges = findBridges(edges, n);
        cout << ans << endl;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
