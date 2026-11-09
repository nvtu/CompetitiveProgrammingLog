#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e2+5);
const long long MOD = int(1e9+7);

int t, n, a[MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) cin >> a[i];
        int ans = 0, cnt = 0;
        for (int i=0; i<n; i++) {
            if (a[i] == 1) {
                ans = max(ans, cnt);
                cnt = 0;
            }
            else cnt++;
        }
        ans = max(ans, cnt);
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
