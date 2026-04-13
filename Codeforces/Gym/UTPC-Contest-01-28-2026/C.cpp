#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int n, q, h[MAX_SIZE], count_stable[MAX_SIZE];

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        count_stable[i] = count_stable[i - 1];
        if (gcd(h[i], i) == 1) {
            count_stable[i]++;
        }
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << count_stable[r] - count_stable[l - 1] << endl;
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
