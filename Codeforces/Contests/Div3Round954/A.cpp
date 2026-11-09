#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, x[3];

void solve() {
    cin >> t;
    while (t--) {
        int ans = INT_MAX;
        for (int i = 0; i < 3; i++) cin >> x[i];
        for (int i = 1; i <= 10; i++) {
            int total = 0;
            for (int j = 0; j < 3; j++) {
                total += abs(x[j] - i);
            }
            ans = min(ans, total);
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
