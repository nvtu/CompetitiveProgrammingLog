#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(5e5 + 5);
const long long MOD = 998244353;
long long n;
int m;

long long exp(long long x, long long mu) {
    long long res = 1LL;
    while (mu > 0) {
        if (mu & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        mu >>= 1;
    }
    return res;
}

void solve() {
    cin >> n >> m;
    vector<long long> a(n + 1, 0LL), k(m + 1, 0LL), c(n + 1, 0LL), l(n + 1, 0LL), r(n + 1, 0LL), ans(m + 1, 0LL);
    long long P = 0, Q = 1;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
        c[i] = i * (n - i + 1);
        Q = (Q * a[i]) % MOD;
        l[i] = r[i] = i;
    }
    for (int i = 1; i <= m; i++) cin >> k[i];
    stack<int> stk;
    for (int i = n; i > 0; i--) {
        while (!stk.empty() && a[i] <= a[stk.top()]) stk.pop();
        if (!stk.empty()) r[i] = stk.top();
        stk.push(i);
    }
    for (int j = 1; j <= m; j++) {
        if (j != 3) continue;
        for (long long i = 1; i <= n; i++) {
            c[i] = (c[i] + (r[i] - i) * k[j]) % MOD;
            c[r[i]] = (c[r[i]] + (n - r[i] + 1) * k[j]) % MOD;
            long long temp = (((Q * exp(a[i], MOD - 2)) % MOD) * c[i]) % MOD;
            ans[j] = (ans[j] + temp) % MOD;
        }
        ans[j] = (ans[j] * exp(Q, MOD - 2)) % MOD;
    }
    for (long long i = 1; i <= m; i++) cout << ans[i] << " ";
}

int main() {
    freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
