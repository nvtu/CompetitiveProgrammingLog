#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n, t, a[205];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        vector<int> ans(n);
        ans[0] = a[n - 1];
        bool ok = true;
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] == a[i + 1]) {
                ok = false;
                break;
            }
            ans[n - 1 - i] = a[i];
        }
        if (ok) {
            for (auto v : ans) cout << v << " ";
        } else
            cout << -1;
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
