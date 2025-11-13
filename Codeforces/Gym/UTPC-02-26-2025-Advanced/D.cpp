#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n, m, r[MAX_SIZE], g[MAX_SIZE], dp[MAX_SIZE];
vector<pair<int, int>> edges[MAX_SIZE];
bool visited[MAX_SIZE];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> r[i] >> g[i];
    for (int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        edges[u].push_back({v, l});
        edges[v].push_back({u, l});
    }
    memset(visited, false, sizeof(visited));
    fill(begin(dp), end(dp), INT_MAX);
    dp[1] = 0;
    pq.push({dp[1], 1});
    while (!pq.empty()) {
        auto [t, u] = pq.top();
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (int i = 0; i < edges[u].size(); i++) {
            auto [v, l] = edges[u][i];
            int rm = t % (r[u] + g[u]);
            int new_time = t + (rm < r[u] ? 0 : r[u] + g[u] - rm);
            if (new_time + l < dp[v]) {
                dp[v] = new_time + l;
                pq.push({dp[v], v});
            }
        }
    }
    cout << dp[n] << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
