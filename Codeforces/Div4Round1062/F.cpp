#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int t, k, n, u, v;

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<vector<int>> e(n);
        vector<int> sz(n, 1);
        for (int i = 0; i < n - 1; i++) {
            cin >> u >> v;
            u--, v--;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        auto dfs = [&](auto& dfs, int v, int p) -> void {
            for (auto u : e[v]) {
                if (u != p) {
                    dfs(dfs, u, v);
                    sz[v] += sz[u];
                }
            }
        };
        dfs(dfs, 0, -1);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (n - sz[i] >= k) ans += sz[i];
            if (sz[i] >= k) ans += n - sz[i];
        }
        cout << ans + n << endl;
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
