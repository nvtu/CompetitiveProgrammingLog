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

int t, x, n;

void solve() {
    cin >> t;
    while (t--) {
        cin >> x >> n;
        int ans = 0;
        for (int i=1; i<=sqrt(x); i++) {
            if (x % i == 0) {
                if ((x / i) >= n) ans = max(ans, i);
                if (i >= n) ans = max(ans, x / i);
            }
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