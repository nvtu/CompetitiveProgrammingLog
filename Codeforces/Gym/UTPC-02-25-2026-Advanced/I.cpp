#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n, x[20], y[20];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    swap(x[0], x[n - 1]);
    swap(y[0], y[n - 1]);
    vector<vector<int>> dist(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        }
    }
    vector<vector<int>> dp(1 << (n - 1), vector<int>(n - 1, MOD));
    for (int mask = 1; mask < (1 << (n - 1)); mask++) {
        for (int i = 0; i < n - 1; i++) {
            if (mask & (1 << i)) {
                int new_mask = mask ^ (1 << i);
                for (int submask = new_mask;; submask = (submask - 1) & new_mask) {
                    int bl = 1e9, br = 1e9;
                    if (submask == 0) bl = 0;
                    if (submask == new_mask) br = 0;
                    for (int j = 0; j < n - 1; j++) {
                        if ((1 << j) & submask) {
                            bl = min(bl, dp[submask][j] + dist[i][j]);
                        } else if ((1 << j) & (new_mask ^ submask)) {
                            br = min(br, dp[new_mask ^ submask][j] + dist[i][j]);
                        }
                    }
                    dp[mask][i] = min(dp[mask][i], max(bl, br));
                    if (submask == 0) break;
                }
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i < n - 1; i++) {
        ans = min(ans, dp[(1 << (n - 1)) - 1][i] + dist[i][n - 1]);
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
