#include <bits/stdc++.h>
using namespace std;

int T, W, H, w, h, x[2], y[2];

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> W >> H >> x[0] >> y[0] >> x[1] >> y[1] >> w >> h;
        int fw = x[1] - x[0], fh = y[1] - y[0];
        if (fw + w > W && fh + h > H) cout << -1 << endl;
        else {
            double ans = 1e9;
            if (fw + w <= W) {
                double mmax = max(x[0], W - x[1]);
                if (mmax >= w) ans = 0;
                else ans = min(ans, w - mmax);
            }
            if (fh + h <= H) {
                double mmax = max(y[0], H - y[1]);
                if (mmax >= h) ans = 0;
                else ans = min(ans, h - mmax);
            }
            cout.precision(9);
            cout << fixed << ans << endl;
        }
    }
    return 0;
}

