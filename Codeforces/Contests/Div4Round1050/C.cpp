#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);
int t, n, m;

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
        sort(v.begin(), v.end());
        int last = 0, ans = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            auto [a, b] = v[i];
            int duration = a - last;
            if (duration & 1) {
                ans += ((b == cur) ? duration - 1 : duration);
            } else {
                ans += ((b == cur) ? duration : duration - 1);
            }
            last = a, cur = b;
        }
        cout << ans + m - last << endl;
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
