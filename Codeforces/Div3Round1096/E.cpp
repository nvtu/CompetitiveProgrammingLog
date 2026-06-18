#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);
int t, n, a[MAX_SIZE], suf_min[MAX_SIZE];
void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        suf_min[n] = MOD;
        long long ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans += 1LL * max(0, a[i] - suf_min[i + 1]);
            suf_min[i] = min(suf_min[i + 1], a[i]);
        }
        int max_suf_min_block = 1, count = 1;
        for (int i = 1; i <= n; i++) {
            if (suf_min[i] == suf_min[i - 1])
                count++;
            else {
                max_suf_min_block = max(max_suf_min_block, count);
                count = 1;
            }
        }
        ans += max_suf_min_block - 1;
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
