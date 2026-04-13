#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int n, m, k, p[MAX_SIZE], visited[MAX_SIZE];
vector<pair<int, int>> e[MAX_SIZE];
set<int> weights;

void dfs(int u, int V) {
    visited[u] = true;
    for (auto edge : e[u]) {
        int v = edge.first, w = edge.second;
        if (w > V || visited[v]) continue;
        dfs(v, V);
    }
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) cin >> p[i];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
        weights.insert(w);
    }
    vector<int> set_weights(weights.size(), 0);
    int j = 0;
    for (auto it = weights.begin(); it != weights.end(); it++) {
        set_weights[j++] = *it;
    }
    int l = 0, r = j, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        bool ok = true;
        for (int i = 1; i <= n; i++) visited[i] = false;
        dfs(p[0], set_weights[mid]);
        for (int i = 0; i < k; i++) {
            if (!visited[p[i]]) ok = false;
        }
        if (ok) {
            ans = set_weights[mid];
            r = mid - 1;
        } else
            l = mid + 1;
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
