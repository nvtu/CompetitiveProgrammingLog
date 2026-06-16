#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, a[8];

void solve() {
    cin >> t;
    while (t--) {
        for (int i = 0; i < 7; i++) cin >> a[i];
        sort(a, a + 7);
        int ans = 0;
        for (int i = 0; i < 6; i++) ans += -a[i];
        ans += a[6];
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
