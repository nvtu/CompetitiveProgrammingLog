#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

long long n, h, t[MAX_SIZE], d[MAX_SIZE], ans;

bool check(long long l) {
    long long cost = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] > l) {
            cost += t[i] * (d[i] - l);
            if (cost >= h) return false;
        }
    }
    return true;
}

void solve() {
    cin >> n >> h;
    long long l = 0, r = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> d[i];
        r = max(r, d[i]);
    }
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
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
