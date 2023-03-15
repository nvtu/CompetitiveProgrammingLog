#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e6+5);
const long long MOD = int(1e9+7);

long long l, r;
long long c1[MAX_SIZE], c2[MAX_SIZE];

void solve() {
    cin >> l >> r;
    c1[0] = 1;
    c2[0] = 1;
    for (int i=1; i<(r+1)/2; i++) {
        c1[i] = (c1[i-1] * 5) % MOD;
        c2[i] = (c2[i-1] * 2) % MOD;
    }
    long long presum=0, ans=0;
    for (int i=0; i<r; i++) {
        if (i == l-1)
            presum = ans;
        ans += (c1[i/2] * 5) % MOD;
        ans += (c2[i/2] * 2) % MOD;
    }
    cout << (ans - presum + MOD) % MOD << endl;
}


int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
