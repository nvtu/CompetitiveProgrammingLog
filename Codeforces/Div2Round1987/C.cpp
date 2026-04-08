#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n;
long long h[MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> h[i];
        long long ans = h[n];
        for (int i = n - 1; i >= 1; i--) {
            ans = max(ans + 1, h[i]);
        }
        cout << ans << endl;
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
