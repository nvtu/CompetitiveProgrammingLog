#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int n, q, d, a[MAX_SIZE], s[MAX_SIZE], g;
double t[MAX_SIZE];

void solve() {
    cin >> n >> q >> d;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) {
        t[i] = 1.0 * (d + a[i]) / s[i];
    }
    sort(t, t + n);
    while (q--) {
        cin >> g;
        double cur_t = 1.0 * (d + n + 1) / g;
        int l = 0, r = n - 1, ans = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (cur_t <= t[mid]) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans + 1 << endl;
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
