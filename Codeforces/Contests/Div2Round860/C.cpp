#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(2e5+5);
const long long MOD = int(1e9+7);

long long t, n, a[MAX_SIZE], b[MAX_SIZE];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
}

void solve() {
    cin >> t;
    while (t--) {
        input();
        long long LCM = b[0], GCD = a[0] * b[0], ans = 0;
        for (int i=1; i<n; i++) {
            long long newGCD = __gcd(GCD, a[i] * b[i]);
            long long newLCM = LCM * b[i] / __gcd(LCM, b[i]);
            if (newGCD % newLCM) {
                ans++;
                LCM = b[i];
                GCD = a[i] * b[i];
            }
            else {
                LCM = newLCM;
                GCD = newGCD;
            }
        }
        ans++;
        cout << ans << endl;
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
