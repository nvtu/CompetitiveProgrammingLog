#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n;
string a, b;

void solve() {
    cin >> n;
    while (n--) {
        cin >> a >> b;
        int n = a.size(), m = b.size();
        int ans = n + m;
        for (int i = 0; i < m; i++) {
            int j = i;
            for (int k = 0; k < n; k++) {
                if (j < m && a[k] == b[j]) j++;
            }
            ans = min(ans, n + m - (j - i));
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
