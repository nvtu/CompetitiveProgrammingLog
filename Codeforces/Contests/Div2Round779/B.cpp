#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, t;
long long pre[505];


int main() {
//    freopen("input.txt", "r", stdin);
    pre[0] = pre[1] = 1;
    for (int i=2; i<505; i++) pre[i] = (pre[i-1] * i) % MOD;
    cin >> t;
    while (t--) {
        cin >> n;
        int nEven = n / 2, nOdd = n / 2;
        long long ans = 0;
        if (n & 1) nOdd++;
        if (nOdd <= nEven) ans = (pre[nOdd] * pre[nEven]) % MOD;
        cout << ans << endl;
    }
    return 0;
}

