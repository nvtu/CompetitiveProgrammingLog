#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

long long n, k;

long long exp(long long a, long long mu) {
    long long res = 1;
    while (mu > 0) {
        if (mu & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        mu >>= 1;
    }
    return res;
}

long long compute_combinatorics(long long n, long long k) {
    long long nominator = 1;
    long long denominator1 = 1;
    long long denominator2 = 1;
    for (long long i = 2; i <= n; i++) {
        nominator = (nominator * i) % MOD;
        if (i <= k) denominator1 = (denominator1 * i) % MOD;
        if (i <= (n - k)) denominator2 = (denominator2 * i) % MOD;
    }
    long long denominator = (denominator1 * denominator2) % MOD;
    return (nominator * exp(denominator, MOD - 2)) % MOD;
}

void solve() {
    cin >> n >> k;
    long long ans = compute_combinatorics((n << 1) - k, n - k) * exp(compute_combinatorics(n << 1, n), MOD - 2);
    ans %= MOD;
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
