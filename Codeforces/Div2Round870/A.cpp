#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

int t, n, L[MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) cin >> L[i];
        sort(L, L+n);
        int ans = -1, l = 0, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int i=n-1; i>=0; i--) {
                if (L[i] > mid) cnt++;
            }
            if (cnt < mid) r = mid - 1;
            else if (cnt > mid) l = mid + 1;
            else {
                ans = mid;
                break;
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
