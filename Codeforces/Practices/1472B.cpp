#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, a[102];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        int count[3] = {0, 0, 0};
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            count[a[i]]++;
        }
        string ans = "YES";
        if (count[2] & 1) {
            if (count[1] < 2) {
                ans = "NO";
            } else {
                count[1] -= 2;
                count[2]++;
            }
        }
        if (!((count[2] & 1) == 0 && (count[1] & 1) == 0)) {
            ans = "NO";
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
