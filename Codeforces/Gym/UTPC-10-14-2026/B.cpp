#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n;
long long k;

void solve() {
    cin >> n >> k;
    vector<long long> a(n);
    long long l = INT_MAX, r = int(2e9), ans = l;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        l = min(l, a[i]);
    }
    while (l <= r) {
        long long m = (l + r) >> 1;
        long long total = 0;
        for (int i = 0; i < n; i++) {
            total += max(0LL, m - a[i]);
        }
        if (total <= k) {
            ans = m;
            l = m + 1;
        } else
            r = m - 1;
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
