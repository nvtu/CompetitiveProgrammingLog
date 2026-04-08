#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n;
long long a[MAX_SIZE], b[MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        vector<bool> changed(n + 1, false);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        int ans = 0;
        int edge_index[2] = {0, n - 1};
        for (int i = 0; i < 2; i++) {
            for (int u = 0; u < 2; u++) {
                int x = edge_index[u];
                int y = (x == 0 ? 1 : n - 2);
                if (!changed[x]) {
                    long long gcd = __gcd(a[x], a[y]);
                    long long lcm = (a[x] * a[y]) / gcd;
                    long long k = b[x] / gcd;
                    for (int j = 1; j <= k; j++) {
                        long long new_v = j * gcd;
                        if (new_v != a[x] && __gcd(new_v, a[y]) == gcd) {
                            a[x] = new_v;
                            changed[x] = true;
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 1; i < n - 1; i++) {
            long long prev_gcd = __gcd(a[i - 1], a[i]);
            long long cur_gcd = __gcd(a[i], a[i + 1]);
            long long lcm = (prev_gcd * cur_gcd) / __gcd(prev_gcd, cur_gcd);
            long long k = b[i] / lcm;
            for (long long j = 1; j <= k; j++) {
                long long new_v = j * lcm;
                if (new_v != a[i] && __gcd(new_v, a[i - 1]) == prev_gcd && __gcd(new_v, a[i + 1]) == cur_gcd) {
                    a[i] = new_v;
                    changed[i] = true;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (changed[i]) ans++;
            // cout << changed[i] << " ";
        }
        // cout << endl;
        // for (int i = 0; i < n; i++) cout << a[i] << " ";
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
