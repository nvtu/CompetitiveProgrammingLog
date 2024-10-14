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


int T, la, lb, ra, rb;

int greatestDigit(int val) {
    int res = 0;
    while (val > 0) {
        res = max(res, val % 10);
        val /= 10;
    }
    return res;
}

void solve() {
    cin >> T;
    while (T--) {
        cin >> la >> ra >> lb >> rb;
        int mmin = la + lb, mmax = ra + rb, ans = 0;
        for (int i=0; i<=min(mmax-mmin, 20); i++) {
            int val = greatestDigit(mmin + i);
            ans = max(ans, val);
        }
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