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

int t, n, a[MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) cin >> a[i];
        int ans = 0;
        int r = n-1, l = 0;
        while (r >= 0 && a[r] == r+1) r--;
        while (l < n && a[l] == l+1) l++;
        if (l < r) {
            bool flag = true;
            for (int i=l; i<=r; i++) {
                if (a[i] == i+1) flag = false;
            }
            ans = flag ? 1 : 2;
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