#include <bits/stdc++.h>
using namespace std;

int n;

long long pow(long long a, long long mu) {
    long long res = 1;
    while (mu > 0) {
        if (mu % 2) res *= a;
        mu >>= 1;
        a *= a;
    }
    return res;
}

int main() {
    // freopen("test.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    int ans = -1;
    if (n == 1) ans = 1;
    for (int i=2; i<=n && ans == -1; i++) {
        int mu = 1;
        while (true) {
            long long res = pow(i, mu);
            if (res == n) ans = i;
            if (res >= n) break;
            mu++;
        }
    }
    cout << ans << endl;
    return 0;
}