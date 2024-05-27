#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

long long t, n, m;

long long getMinPrimeDivisor(long long x) {
    for (long long i=2; i*i<=x; i++) {
        if (x % i == 0) return i;
    }
    return x;
}

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        string ans = "YES";
        long long minPrime = getMinPrimeDivisor(n);
        if ((n & 1) == 0 || n <= m || m >= minPrime) ans = "NO";
        if (m == 1 || n == 1) ans = "YES";
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
