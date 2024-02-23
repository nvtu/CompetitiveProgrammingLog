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
const int MMAX = MOD;

int t, n;

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0;
        int mmax = int(sqrt(2*n-1));
        if (mmax % 2 == 0) mmax--;
        if (mmax - 3 >= 0) ans = (mmax - 3) / 2 + 1;
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