#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, x, y;

void solve() {
    cin >> t;
    while (t--) {
        cin >> x >> y;
        if (y < x || (x == 0 && (y % 2 == 0))) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            if (x == 0 && y == 1) continue;
            vector<pair<int, int>> ans;
            int cur_node = 1, root = 1;
            for (int i = 0; i < x; i++) {
                ans.push_back({cur_node, cur_node + 1});
                cur_node++;
                if (i + 1 < x) {
                    ans.push_back({cur_node, cur_node + 1});
                    cur_node++;
                }
            }
            int r = y - x;
            if (r % 2) {
                r--;
                ans.push_back({cur_node, cur_node + 1});
                cur_node += 2;
                if (x > 0) {
                    root = 2;
                } else {
                    r--;
                }
            } else
                cur_node++;
            for (int i = 0; i < r; i++) {
                ans.push_back({root, cur_node});
                cur_node++;
            }
            for (auto v : ans) cout << v.first << " " << v.second << endl;
        }
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
