#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);
int t, n, k, x, a[MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> k >> x;
        for (int i = 0; i < n; i++) cin >> a[i];
        a[n] = 1e-9;
        a[n + 1] = 1e9;
        vector<int> ans;
        sort(a, a + n + 2);
        int l = 0, r = x + 1;
        while (l < r) {
            int m = (l + r + 1) >> 1, total = 0;
            a[0] = -m, a[n + 1] = x + m;
            for (int i = 1; i <= n + 1; i++) {
                total += max(0, (a[i] - m) - (a[i - 1] + m) + 1);
            }
            if (total >= k)
                l = m;
            else
                r = m - 1;
        }
        a[0] = -l, a[n + 1] = x + l;
        int j = 0;
        for (int i = 1; i <= n + 1; i++) {
            for (j = max(j, a[i - 1] + l); j <= min(x, a[i] - l) && k; j++) {
                cout << j << " ";
                k--;
            }
        }
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
