#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n;
int64_t x;

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        int64_t ans = 0;
        vector<int64_t> odd;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x & 1)
                odd.push_back(x);
            else
                ans += x;
        }
        sort(odd.begin(), odd.end(), greater<int64_t>());
        if (odd.size() == 0)
            ans = 0;
        else {
            int l = 0, r = odd.size();
            while (l < r) {
                ans += odd[l++];
                r--;
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
