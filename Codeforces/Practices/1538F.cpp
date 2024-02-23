#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstdlib>
#include <set>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);
const double EPS = 1e-6;

int t, l, r;

long long countDigitChanged(int n) {
    long long res = 0;
    long long mul = 1;
    while (n > 0) {
        int digit = n % 10;
        res += digit * mul;
        mul = (mul * 10) + 1;
        n /= 10;
    }
    return res;
}

void solve() {
    cin >> t;
    while (t--) {
        cin >> l >> r;
        long long ans = countDigitChanged(r) - countDigitChanged(l);
        cout << ans << endl;
    }
}


int main() {
    // freopen("inp.txt", "r", stdin);

    //Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}