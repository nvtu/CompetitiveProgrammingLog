#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);
long long t, n, k;
long long a[MAX_SIZE], c;

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> c >> k;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        for (int i = 0; i < n; i++) {
            int flip_flop = min(c - a[i], k);
            if (a[i] <= c) {
                c += a[i];
                if (flip_flop > 0) {
                    c += flip_flop;
                    k -= flip_flop;
                }
            }
        }
        cout << c << endl;
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
