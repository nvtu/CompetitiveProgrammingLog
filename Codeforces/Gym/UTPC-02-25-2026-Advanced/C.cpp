#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n, k, a[20], ans;

void remove_hair(int i, int k) {
    if (i == n) {
        ans = min(ans, k);
        return;
    }
    remove_hair(i + 1, k);
    if (a[i] < k) {
        remove_hair(i + 1, k - a[i]);
    }
}

void solve() {
    cin >> n >> k;
    ans = k;
    for (int i = 0; i < n; i++) cin >> a[i];
    remove_hair(0, k);
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
