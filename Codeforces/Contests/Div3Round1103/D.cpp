#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, k, x, cnt[MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        memset(cnt, 0, sizeof(cnt));
        int mmax = 0;
        cin >> n >> k;
        vector<int> a;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (cnt[x] == 0) a.push_back(x);
            cnt[x]++;
            mmax = max(mmax, x);
        }
        sort(a.begin(), a.end());
        int sz = a.size();
        bool ok = false;
        for (int i = sz - 1; i >= 0 && !ok; i--) {
            if (cnt[a[i]] % 2 == 0) {
                ok = true;
            } else {
                int pos = lower_bound(a.begin(), a.begin() + i, a[i] - k) - a.begin();
                if (pos < i) {
                    ok = true;
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
