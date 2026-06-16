#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int n;
long long b, x, a[MAX_SIZE];

bool check_possible(long long v) {
    long long supply = b;
    for (int i = 0; i < n; i++) {
        long long need = (v * a[i] + x - 1) / x;
        supply -= need;
        if (supply < 0) return false;
    }
    return true;
}

void solve() {
    cin >> n >> b >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    long long l = 0, r = (long long)1e12 + 7, ans = 0;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (check_possible(mid)) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
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
