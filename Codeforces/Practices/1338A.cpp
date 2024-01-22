#include <iostream>
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

int t, n, a[MAX_SIZE];


void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        long long sum = 0;
        for (int i=0; i<n; i++) cin >> a[i];
        long long ans = 0;
        for (int i=1; i<n; i++) {
            if (a[i] < a[i-1]) {
                long long gap = a[i-1] - a[i];
                long long step = 0;
                while (gap > 0) {
                    step++;
                    gap >>= 1;
                }
                a[i] = a[i-1];
                ans = max(ans, step);
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

