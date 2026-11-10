#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n;
string s;

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int dp[n];
        memset(dp, 0, sizeof(dp));
        if (s[0] == '@') dp[0] = 1;
        bool ok = true;
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1];
            if (ok) {
                if (s[i] == '*') {
                    if (s[i - 1] == '*') {
                        ok = false;
                    }
                } else if (s[i] == '@') {
                    dp[i] = dp[i - 1] + 1;
                }
            }
        }
        cout << dp[n - 1] << endl;
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
