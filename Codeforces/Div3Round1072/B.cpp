#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, k, s, m;

void solve() {
    cin >> t;
    while (t--) {
        cin >> s >> k >> m;
        if (k >= s) {
            cout << (m % k < s ? s - m % k : 0) << endl;
        } else {
            cout << ((m % (2 * k)) < k ? s - m % k : k - m % k) << endl;
        }
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
