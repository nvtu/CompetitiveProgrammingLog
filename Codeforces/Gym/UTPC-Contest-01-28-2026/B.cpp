#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int n;
long long t, a[MAX_SIZE];

void solve() {
    cin >> n >> t;
    long long mmax = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mmax = max(mmax, a[i]);
    }
    long long acc_delay = accumulate(a + 1, a + n + 1, 0LL);
    long long ans = 0;
    if (t >= acc_delay) {
        ans = (t - acc_delay) / mmax + 1;
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
