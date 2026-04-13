#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int n, m;
long long p[MAX_SIZE];
vector<bool> visited;

void dfs(int u, vector<vector<int>>& edge, vector<int>& output) {
    visited[u] = true;
    for (auto v : edge[u]) {
        if (!visited[v]) {
            dfs(v, edge, output);
        }
    }
    output.push_back(u);
}

void strongly_connected_components(vector<vector<int>>& edge, vector<vector<int>>& components) {
    // Build the sorted list of G vertices by the exit time in increasing order
    vector<int> order;
    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, edge, order);
        }
    }
    // Build graph transpose G^T
    vector<vector<int>> edge_r(n + 1);
    for (int i = 1; i <= n; i++) {
        for (auto v : edge[i]) {
            edge_r[v].push_back(i);
        }
    }
    reverse(order.begin(), order.end());
    visited.assign(n + 1, false);
    // Construct SCCs
    for (auto u : order) {
        if (!visited[u]) {
            vector<int> component;
            dfs(u, edge_r, component);
            components.push_back(component);
        }
    }
}

void dfs_dp(int u, vector<vector<int>>& edge, vector<long long>& p, vector<long long>& dp) {
    if (visited[u]) return;
    visited[u] = true;
    long long max_score = 0;
    for (auto v : edge[u]) {
        dfs_dp(v, edge, p, dp);
        max_score = max(max_score, dp[v]);
    }
    dp[u] = max(dp[u], max_score + p[u]);
}

void solve() {
    cin >> n >> m;
    vector<vector<int>> edge(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
    }
    vector<vector<int>> sccs;
    strongly_connected_components(edge, sccs);
    // Construct condense graph
    int v_count = 0;
    vector<vector<int>> edge_cond, edge_cond_r;
    vector<int> org_root(n + 1, 0);
    vector<long long> newp;
    newp.push_back(0);
    for (auto scc : sccs) {
        v_count++;
        long long new_point = 0;
        for (auto u : scc) {
            new_point += p[u];
            org_root[u] = v_count;
        }
        newp.push_back(new_point);
    }
    edge_cond.assign(v_count + 1, {});
    edge_cond_r.assign(v_count + 1, {});
    for (int u = 1; u <= n; u++) {
        for (auto v : edge[u]) {
            if (org_root[u] != org_root[v]) {
                edge_cond[org_root[u]].push_back(org_root[v]);
                edge_cond_r[org_root[v]].push_back(org_root[u]);
            }
        }
    }
    // Dp on graph
    vector<long long> dp_start(v_count + 1, 0LL), dp_end(v_count + 1, 0LL);
    visited.assign(v_count + 1, false);
    for (int u = 1; u <= v_count; u++) {
        dfs_dp(u, edge_cond, newp, dp_start);
    }
    visited.assign(v_count + 1, false);
    for (int u = 1; u <= v_count; u++) {
        dfs_dp(u, edge_cond_r, newp, dp_end);
    }
    long long ans = 0;
    for (int u = 1; u <= v_count; u++) {
        ans = max(ans, dp_start[u] + dp_end[u] - newp[u]);
    }
    cout << ans << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
