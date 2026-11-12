#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n, a[MAX_SIZE];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<bool> dec(n + 2, false), inc(n + 2, false);
    a[0] = int(2e9), a[n + 1] = 0;
    dec[0] = inc[0] = true, dec[n + 1] = inc[n + 1] = true;
    for (int i = 1; i <= n; i++) {
        dec[i] = dec[i - 1];
        if (a[i] <= a[i - 1])
            dec[i] = dec[i] & 1;
        else
            dec[i] = dec[i] & 0;
    }
    for (int i = n; i > 0; i--) {
        inc[i] = inc[i + 1];
        if (a[i] >= a[i + 1])
            inc[i] = inc[i] & 1;
        else
            inc[i] = inc[i] & 0;
    }
    if (dec[n]) {
        cout << 0 << endl;
        return;
    }
    int R = n + 1;
    while (R > 1 && inc[R - 1]) R--;
    int ans = n;
    for (int i = R; i <= n + 1; i++) {
        int ll = 0, rr = n, p = 0;
        while (ll <= rr) {
            int m = (ll + rr) >> 1;
            if (a[m] >= a[i] && dec[m]) {
                p = m;
                ll = m + 1;
            } else
                rr = m - 1;
        }
        if (p != -1) {
            ans = min(ans, i - p - 1);
        }
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
