#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n;
long long d, h, c[MAX_SIZE];

void solve() {
    cin >> n >> d >> h;
    for (int i = 0; i < n; i++) cin >> c[i];
    long long l = 0, r = 1e9, ans = 0;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (c[i] - mid * d > h) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
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
