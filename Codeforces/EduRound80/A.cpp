#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int T, n, d;

void solve() {
    cin >> T;
    while (T--) {
        cin >> n >> d;
        int l = 0, r = n / 2, ans = -1;
        while (l <= r) {
            int x = (l + r) >> 1;
            int v = x - n + (d + x) / (x + 1);
            if (v > 0) {
                l = x + 1;
            } else {
                r = x - 1;
                ans = x;
            }
        }
        cout << (ans != -1 ? "YES" : "NO") << endl;
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
