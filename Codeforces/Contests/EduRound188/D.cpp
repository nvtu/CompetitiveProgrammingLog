#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, m, u, v;
vector<int> e[MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> side(n + 1, -1);
        queue<int> q;
        for (int i = 1; i <= n; i++) e[i].clear();
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (side[i] == -1) {
                bool is_bipartite = true;
                vector<int> cc;
                side[i] = 0;
                q.push(i);
                while (!q.empty()) {
                    v = q.front();
                    cc.push_back(v);
                    q.pop();
                    for (int u : e[v]) {
                        if (side[u] == -1) {
                            side[u] = side[v] ^ 1;
                            q.push(u);
                        } else
                            is_bipartite &= side[u] != side[v];
                    }
                }
                if (is_bipartite) {
                    int colors[2] = {0, 0};
                    for (int u : cc) colors[side[u]]++;
                    ans += max(colors[0], colors[1]);
                }
            }
        }
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
