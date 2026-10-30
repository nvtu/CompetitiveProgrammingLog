#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(5e3 + 5);
const long long MOD = int(1e9 + 7);

long long n, t, a[MAX_SIZE];

void solve() {
    cin >> n >> t;
    long long C = 0, S = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        long long _lcm = 1;
        for (int j = i; j < n; j++) {
            _lcm = lcm(_lcm, a[j]);
            if (_lcm <= t) {
                C++, S += 1LL * (j - i + 1);
            } else
                break;
        }
    }
    cout << C << " " << S << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
