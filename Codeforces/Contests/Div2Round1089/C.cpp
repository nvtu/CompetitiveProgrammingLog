#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n;
long long a[MAX_SIZE], b[MAX_SIZE];

bool check_found(int i, long long v) {
    long long k = b[i] / v;
    for (long long j = 1; j <= k; j++) {
        long long new_v = j * v;
        if (new_v != a[i]) {
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        vector<bool> changed(n + 2, false);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        int ans = 0;
        for (int i = 2; i < n; i += 2) {
            long long prev_gcd = __gcd(a[i - 1], a[i]);
            long long cur_gcd = __gcd(a[i], a[i + 1]);
            long long lcm = (prev_gcd * cur_gcd) / __gcd(prev_gcd, cur_gcd);
            for (int t = 0; t < 3; t++) {
                if (changed[i - 1 + t]) continue;
                long long k = b[i - 1 + t] / lcm;
                for (long long j = 1; j <= k; j++) {
                    if (lcm > 1 && j % lcm == 0) continue;
                    long long new_v = j * lcm;
                    if (new_v != a[i - 1 + t]) {
                        a[i - 1 + t] = new_v;
                        changed[i - 1 + t] = true;
                        break;
                    }
                }
            }
        }
        // if (!changed[0]) {
        //     long long lcm = a[0] / __gcd(a[0], a[1]) * a[1];
        //     for (int i = 0; i < 2; i++) {
        //         if (changed[i]) continue;
        //         long long k = b[i] / lcm;
        //         for (long long j = 1; j <= k; j++) {
        //             if (lcm > 1 && j % lcm == 0) continue;
        //             long long new_v = j * lcm;
        //             if (new_v != a[i]) {
        //                 if (n > 2 && i == 1) continue;
        //                 a[i] = new_v;
        //                 changed[i] = true;
        //                 break;
        //             }
        //         }
        //     }
        // }
        // if (n > 2 && !changed[n - 1]) {
        //     long long lcm = a[n - 1] / __gcd(a[n - 1], a[n - 2]) * a[n - 2];
        //     for (int i = 0; i < 2; i++) {
        //         if (changed[n - 2 + i]) continue;
        //         long long k = b[n - 2 + i] / lcm;
        //         for (long long j = 1; j <= k; j++) {
        //             if (gcd > 1 && j % lcm == 0) continue;
        //             long long new_v = j * lcm;
        //             if (new_v != a[n - 2 + i]) {
        //                 if (n > 2 && i + n - 2 == n - 2) continue;
        //                 a[n - 2 + i] = new_v;
        //                 changed[n - 2 + i] = true;
        //                 break;
        //             }
        //         }
        //     }
        // }

        for (int i = 1; i <= n; i++) {
            if (changed[i]) ans++;
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
