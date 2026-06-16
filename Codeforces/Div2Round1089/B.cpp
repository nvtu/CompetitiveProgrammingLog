#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, p[MAX_SIZE];

bool check(int v) {
    vector<bool> avail(n + 1, false);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (avail[i]) break;
        if (p[i] <= i) {
            cnt++;
            avail[p[i]] = true;
        }
    }
    return cnt >= v;
}

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> p[i];
        int ans = 0;
        vector<bool> avail(n + 1, false);
        for (int i = 1; i <= n; i++) {
            if (avail[p[i]]) break;
            if (p[i] <= i) {
                ans++;
                avail[p[i]] = true;
            }
        }
        // int l = 1, r = n, ans = 1;
        // while (l <= r) {
        //     int mid = (l + r) >> 1;
        //     if (check(mid)) {
        //         l = mid + 1;
        //         ans = mid;
        //     } else
        //         r = mid - 1;
        // }
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
