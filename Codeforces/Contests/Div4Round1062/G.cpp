#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e4 + 5);
const long long MOD = int(1e9 + 7);
long long t, n, a[MAX_SIZE], c[MAX_SIZE], f[MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> c[i];
        for (int i = 0; i < n; i++) f[i] = c[i];
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (a[j] <= a[i]) {
                    f[i] = max(f[i], f[j] + c[i]);
                }
            }
        }
        cout << accumulate(c, c + n, 0LL) - *max_element(f, f + n) << endl;
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
