#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, h[6];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        int mmax = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> h[i];
            mmax = max(mmax, h[i]);
        }
        for (int i = 0; i < n; i++) {
            ans = max(ans, mmax + 1 - h[i]);
        }
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
