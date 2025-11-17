#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, k;

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a(n);
        vector<int> total(n + 1, 0), count(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            total[a[i]]++;
        }
        bool ok = ((n % k) == 0);
        for (int i = 1; i <= n; i++) {
            if (total[i] % k) {
                ok = false;
                break;
            }
        }
        int64_t ans = 0;
        if (ok) {
            int64_t l = 0, r = l;
            while (r < n) {
                count[a[r++]]++;
                while (l < r && count[a[r - 1]] * k > total[a[r - 1]]) count[a[l++]]--;
                ans += r - l;
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
