#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t;
long long n, m, a, b;

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> m >> a >> b;
        if (__gcd(a, n) == 1 && __gcd(b, m) == 1 && __gcd(n, m) <= 2) {
            cout << "YES" << endl;
        } else
            cout << "NO" << endl;
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
