#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, a[MAX_SIZE];

int find_mex(int l, int r) {
    set<int> s;
    for (int i = 0; i <= n; i++) s.insert(i);
    while (l >= 0 && r < 2 * n && a[l] == a[r]) {
        s.erase(a[l]);
        l--, r++;
    }
    return *s.begin();
}

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < 2 * n; i++) cin >> a[i];
        int l = -1, r = 2 * n - 1;
        for (int i = 0; i < 2 * n; i++) {
            if (!a[i]) {
                if (l == -1)
                    l = i;
                else
                    r = i;
            }
        }
        cout << max({find_mex(l, l),
                     find_mex(r, r),
                     find_mex((l + r) / 2, (l + r + 1) / 2)})
             << endl;
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
