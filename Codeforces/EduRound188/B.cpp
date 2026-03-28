#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, a[MAX_SIZE], mmax[MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mmax[i] = max(mmax[i - 1], a[i]);
        }
        int ans = 0;
        for (int i = n; i > 0; i--) {
            if (mmax[i] == a[i]) {
                ans++;
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
