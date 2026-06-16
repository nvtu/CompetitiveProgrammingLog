#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, dp[MAX_SIZE];
char s[2][MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> s[i][j];
            }
        }
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            if (s[0][i] != s[1][i]) dp[i]++;
            if (i - 2 >= 0) {
                if (s[0][i] == s[0][i - 1]) {
                    if (s[1][i] == s[1][i - 1]) {
                        dp[i] = min(dp[i], dp[i - 2]);
                    } else {
                        dp[i] = min(dp[i], dp[i - 2] + 1);
                    }
                } else {
                    if (s[1][i] == s[1][i - 1]) {
                        dp[i] = min(dp[i], dp[i - 2] + 1);
                    } else {
                        dp[i] = min(dp[i], dp[i - 2] + 2);
                    }
                }
            }
        }
        cout << dp[n] << endl;
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
