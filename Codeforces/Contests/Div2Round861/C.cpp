#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

long long t, l, r, ans = -1, targetOpt = LLONG_MAX;

long long findMul(long long x) {
    long long mul = 1;
    while (x > 0) {
        x /= 10;
        mul *= 10;
    }
    return mul / 10;
}



void solve() {
    cin >> t;
    while (t--) {
        cin >> l >> r;
        targetOpt = LLONG_MAX, ans = -1;
        long long mulL = findMul(l);
        long long mulR = findMul(r);
        if (mulR > mulL) ans = mulL * 10 - 1;
        else { 
            for (int i=0; i<10; i++) {
                long long temp = 0;
                for (int j=0; j<10; j++) {
                    int k = j + i;
                    if (k >= 10) continue;
                    long long ltemp = (l % mulL > 10 ? 0 : l % mulL);
                    long long rtemp = (r % mulR > 10 ? 0 : r % mulR);
                }
            }
        }
        cout << ans << endl;
    }
}


int main() {
    freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
