#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

long long n, m;

long long pow(long long a, long long mu) {
    long long ans = 1;
    while (mu > 0) {
        if (mu & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        mu >>= 1;
    }
    return ans;
}

long long comb(long long n, long long k) {
    long long x = 1;
    for (long long i = 2; i <= min(k, n - k); i++) {
        x = (x * i) % MOD;
    }
    long long y = x;
    for (long long i = min(k, n - k) + 1; i <= max(k, n - k); i++) {
        y = (y * i) % MOD;
    }
    long long nominator = y;
    for (long long i = max(k, n - k) + 1; i <= n; i++) {
        nominator = (nominator * i) % MOD;
    }
    long long denominator = pow((x * y) % MOD, MOD - 2);
    return (nominator * denominator) % MOD;
}

void solve() {
    cin >> n >> m;
    long long ans = comb(2 * m + n - 1, n - 1);
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
