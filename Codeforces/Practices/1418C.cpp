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

const int MAX_SIZE = int(2e5+5);
const long long MOD = int(1e9+7);
const double EPS = 1e-6;
const int FIRST = 0;
const int SECOND = 1;

int t, n, a[MAX_SIZE], dp[MAX_SIZE][2];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        memset(dp, 0, sizeof(dp));
        for (int i=1; i<=n; i++) cin >> a[i];
        dp[1][FIRST] = a[1];
        dp[1][SECOND] = 0;
        dp[2][FIRST] = dp[1][FIRST] + a[2];
        dp[2][SECOND] = dp[1][FIRST];
        for (int i=3; i<=n; i++) {
            dp[i][SECOND] = min(dp[i-1][FIRST], dp[i-2][FIRST]);
            dp[i][FIRST] = dp[i-1][SECOND] + a[i];
            if (i-2 > 1) 
                dp[i][FIRST] = min(dp[i][FIRST], dp[i-2][SECOND] + a[i-1] + a[i]); 
        }
        int ans = min(dp[n][FIRST], dp[n][SECOND]);
        if (n == 1) ans = dp[n][FIRST];
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