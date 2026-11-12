#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int k;
long long c[MAX_SIZE];

long long pow(long long a, long long m) {
    long long ans = 1;
    while (m > 0) {
        if (m & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        m >>= 1;
    }
    return ans;
}

void solve() {
    cin >> k;
    for (int i = 0; i < k; i++) cin >> c[i];
    long long total = accumulate(c, c + k, 0);
    sort(c, c + k);
    vector<long long> d(c[k - 1] + 1, 1);
    long long ans = 1;
    for (long long i = 2; i <= total; i++) {
        ans = (ans * i) % MOD;
    }
    for (long long i = 2; i <= c[k - 1]; i++) {
        d[i] = (d[i - 1] * pow(i, MOD - 2)) % MOD;
    }
    for (int i = 0; i < k; i++) {
        ans = (ans * d[c[i]]) % MOD;
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
