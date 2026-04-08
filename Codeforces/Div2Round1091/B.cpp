#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, k;

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a(n, 0), p(k, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < k; i++) {
            cin >> p[i];
            p[i]--;
        }
        int x = a[p[0]];
        bool flipped = false;
        int al = 0, ar = n - 1, ans = 0;
        while (true) {
            while (al < p[0]) {
                if (flipped) a[al] = 1 - a[al];
                if (a[al] == x)
                    al++;
                else
                    break;
            }
            while (ar > p[0]) {
                if (flipped) a[ar] = 1 - a[ar];
                if (a[ar] == x)
                    ar--;
                else
                    break;
            }
            if (al <= ar) {
                if (al == ar) {
                    if (flipped) ans++;
                    break;
                } else {
                    ans++;
                    flipped = !flipped;
                    if (al < p[0]) al++;
                    if (ar > p[0]) ar--;
                }
            } else
                break;
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
