#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
// const long long MOD = int(1e9 + 7);
const long long MOD = 676767677;

int t;
long long x, y;

long long exp(long long a, long long n) {
    long long ans = 1;
    while (n > 0) {
        if (n & 1) ans = (ans * a) % MOD;
        n >>= 1;
        a = (a * a) % MOD;
    }
    return ans;
}

void solve() {
    cin >> t;
    while (t--) {
        cin >> x >> y;
        long long ans = 1;
        vector<int> res;
        pair<long long, int> z[2] = {{x, 1}, {y, -1}};
        if (z[0] > z[1]) swap(z[0], z[1]);
        long long diff = z[1].first - z[0].first;
        for (int i = 0; i < z[0].first; i++) res.push_back(z[0].second);
        for (int i = 0; i < z[1].first; i++) res.push_back(z[1].second);
        if (diff == 0) {
            ans = 1;
        } else {
            ans = 0;
            for (int i = 1; i <= sqrt(diff); i++) {
                if (diff % i == 0) {
                    if (diff / i != i) {
                        ans = (ans + 2) % MOD;
                    } else
                        ans = (ans + 1) % MOD;
                }
            }
        }
        cout << ans << endl;
        for (int v : res) cout << v << " ";
        cout << endl;
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
