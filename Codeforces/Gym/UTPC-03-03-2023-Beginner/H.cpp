#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e6+5);
const long long MOD = int(1e9+7);
const int B = 1;
const int S = 0;

long long n, k;
long long f[MAX_SIZE][2], pSum[MAX_SIZE];

void initialize()  { 
    f[0][B] = f[0][S] = 1;
    f[1][B] = f[1][S] = 1;
    pSum[0] = 1;
    pSum[1] = 2;
}

void solve() {
    cin >> n >> k;
    initialize();
    for (int i=2; i<=n; i++) {
        f[i][B] = (f[i-1][B] + f[i-1][S]) % MOD;
        f[i][S] = pSum[i-1];
        if (i >= k) {
            f[i][S] = (f[i][S] - pSum[i-k] + MOD) % MOD;
        }
        pSum[i] = (pSum[i-1] + f[i][B]) % MOD;
        // cout << i << " " << pSum[i] << " " << f[i][S] << " " << f[i][B] << endl;
    }
    long long ans = (f[n][B] + f[n][S]) % MOD;
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
