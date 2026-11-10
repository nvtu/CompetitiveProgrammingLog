#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, k, n, a[MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> a[i];
        int psum[n], dp[n][2];
        memset(dp, 0, sizeof(dp));
        psum[0] = a[0];
        if (a[0] == 0 && k == 1) dp[0][1] = 1;
        for (int i = 1; i < n; i++) {
            psum[i] = psum[i - 1] + a[i];
        }
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            if (i - k >= 0) {
                int sum = psum[i] - psum[i - k];
                if (sum == 0) {
                    dp[i][1] = max(dp[i][0], dp[i - k][0] + 1);
                }
            } else if (i == k - 1) {
                int sum = psum[i];
                if (sum == 0) dp[i][1] = 1;
            }
        }
        cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
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
