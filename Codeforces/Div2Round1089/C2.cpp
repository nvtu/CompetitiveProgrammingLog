#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, dp[MAX_SIZE][23];
long long a[MAX_SIZE], b[MAX_SIZE], lcms[MAX_SIZE];
vector<int> primes = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73};
const int L = primes.size();

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
        for (int i = 0; i < n; i++) scanf("%lld", &b[i]);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long gcds[2] = {(i >= 1 ? __gcd(a[i], a[i - 1]) : __gcd(a[i], a[i + 1])),
                                 (i + 1 < n ? __gcd(a[i], a[i + 1]) : __gcd(a[i], a[i - 1]))};
            long long lcm = (gcds[0] * gcds[1]) / __gcd(gcds[0], gcds[1]);
            lcms[i] = (lcm > b[i] ? a[i] : lcm);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < L; j++) dp[i][j] = 0;
        }
        for (int j = 0; j < L; j++) {
            long long new_v = primes[j] * lcms[0];
            bool ok = true;
            if (new_v == a[0]) ok = false;
            if (new_v > b[0]) ok = false;
            if (__gcd(new_v, lcms[1]) != __gcd(a[0], a[1])) ok = false;
            if (ok) dp[0][j] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < L; j++) {
                long long new_v = primes[j] * lcms[i];
                bool ok1 = true;
                if (new_v == a[i]) ok1 = false;
                if (new_v > b[i]) ok1 = false;
                if (i + 1 < n && __gcd(new_v, lcms[i + 1]) != __gcd(a[i], a[i + 1])) ok1 = false;
                for (int k = 0; k < L; k++) {
                    long long prev_v = primes[k] * lcms[i - 1];
                    bool ok2 = ok1;
                    if (__gcd(new_v, prev_v) != __gcd(a[i], a[i - 1])) ok2 = false;
                    if (ok2) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][k] + 1);
                    } else {
                        dp[i][j] = max(dp[i][j], dp[i - 1][k]);
                    }
                }
            }
        }
        for (int i = 0; i < primes.size(); i++) {
            ans = max(ans, dp[n - 1][i]);
        }
        // cout << ans << endl;
        printf("%d\n", ans);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    solve();
    return 0;
}