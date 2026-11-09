#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n;
string s;

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int ans = 1;
        int cur = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') {
                cur++;
                ans = max(ans, cur);
            } else
                break;
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
