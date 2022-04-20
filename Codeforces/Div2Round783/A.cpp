#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int ans = 0;
        if (n > m) swap(n, m);
        if (n == 1) {
            if (m == 2) ans = 1;
            else if (m > 2) ans = -1;
        }
        else {
            ans += 2 * (n-2);
            int j = max(0, n-2), k = m - j;
            ans += (k - 1) << 1;
            if (k & 1) ans--;
        }
        cout << ans << endl;
    }
    return 0;
}

