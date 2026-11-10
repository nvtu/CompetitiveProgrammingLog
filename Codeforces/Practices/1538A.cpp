#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, a[105];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        int mmin = MOD, min_p = 0, mmax = 0, max_p = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] < mmin) {
                mmin = a[i];
                min_p = i;
            }
            if (a[i] > mmax) {
                mmax = a[i];
                max_p = i;
            }
        }
        if (max_p < min_p) swap(max_p, min_p);
        ans = min(n - min_p, min(n - max_p + min_p + 1, max_p + 1));
        cout << ans << endl;
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
