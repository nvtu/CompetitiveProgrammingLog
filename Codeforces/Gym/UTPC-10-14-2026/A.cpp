#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n, m;

void solve() {
    cin >> n >> m;
    vector<int> s(n), a(m);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < m; i++) cin >> a[i];
    sort(a.begin(), a.end());
    sort(s.begin(), s.end());
    int ans = 0;
    int l = 0, r = m - 1;
    for (int i = 0; i < n; i++) {
        int pos = -1;
        int ll = l, rr = r;
        while (ll <= rr) {
            int mid = (ll + rr) >> 1;
            if (a[mid] <= s[i]) {
                pos = mid;
                ll = mid + 1;
            } else
                rr = mid - 1;
        }
        if (pos >= l) {
            ans++;
            l++;
        }
    }
    cout << ans << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
