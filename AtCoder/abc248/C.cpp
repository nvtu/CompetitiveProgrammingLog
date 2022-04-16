#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int N, M, K;

int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M >> K;
    if (N == 1) {
        cout << M << endl;
        return 0;
    }
    long long ans = 0;
    for (int i=1; i<=M; i++) {
        long long div = (K - i) / (N - 1);
        if (div > M) break;
        long long rem = (K - i) % (N - 1);
        long long prod = 1;
        for (int j=0; j<rem; j++) {
            if (div + 1 <= M) prod = (prod * (div + 2 - i)) % MOD; 
        }
        for (int j=0; j<N-1-rem; j++) {
            prod = (prod * (div - i + 1)) % MOD;
        }
        ans = (ans + prod) % MOD;
    }
    cout << ans << endl;
    return 0;
}

