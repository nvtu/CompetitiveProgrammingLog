#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int t;
long long a[3], m, ans[3];

void solve() {
    cin >> t;
    while (t--) {
        for (int i = 0; i < 3; i++) {
            cin >> a[i];
            ans[i] = 0;
        }
        cin >> m;
        long long x = (a[0] * a[1]) / __gcd(a[0], a[1]);
        x = (x * a[2]) / __gcd(x, a[2]);
        x = m / x;
        for (int i = 0; i < 3; i++) {
            ans[i] += x * 2;
        }
        for (int i = 0; i < 3; i++) {
            long long t = 0;
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                t += m / ((a[i] * a[j]) / __gcd(a[i], a[j]));
            }
            t -= x * 2;
            ans[i] += t * 3;
            ans[i] += (m / a[i] - t - x) * 6;
        }
        for (int i = 0; i < 3; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
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