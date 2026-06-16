#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);
int t;
string s;

void solve() {
    cin >> t;
    while (t--) {
        cin >> s;
        int l = 1, r = (int)s.size() - 2;
        while (l < s.size() && s[l] != s[l - 1]) l++;
        while (r >= 0 && s[r] != s[r + 1]) r--;
        bool ok = true;
        if (l <= r) {
            for (int i = l + 1; i <= r; i++) {
                if (s[i] == s[i - 1]) {
                    ok = false;
                    break;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
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
