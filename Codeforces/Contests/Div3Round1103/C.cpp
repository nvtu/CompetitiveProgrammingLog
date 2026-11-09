#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, a, b, x;

void solve() {
    cin >> t;
    while (t--) {
        cin >> a >> b >> x;
        int ans = max(a, b) - min(a, b), count = 0;
        while (a != b) {
            if (a > b) swap(a, b);
            ans = min(ans, count + max(a, b) - min(a, b));
            while (b > a) {
                b /= x;
                count++;
                ans = min(ans, count + max(a, b) - min(a, b));
            }
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
