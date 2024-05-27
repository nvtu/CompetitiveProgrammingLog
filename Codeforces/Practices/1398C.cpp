#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);
int t, n;
string a;

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> a;
        long long ans = 0;
        vector<int> psum(n + 1, 0);
        map<int, int> cnt;
        for (int i = 1; i <= n; i++) {
            psum[i] = psum[i - 1] + (a[i - 1] - '0' - 1);
            cnt[psum[i]]++;
        }
        ans = cnt[0];
        for (auto [key, value] : cnt) {
            ans += 1LL * value * (value - 1) / 2;
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
