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
#include <cstring>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(8e3+5);
const long long MOD = int(1e9+7);
const double EPS = 1e-6;

int t, n, a[MAX_SIZE], psum[MAX_SIZE];

bool checkPerfect(int L, int R, int index) {
    for (int j=R; j>=L; j--) {
        int l = L-1, r = j;
        while (l <= r) {
            int mid = (l+r)>>1;
            if (psum[j] - psum[mid] == a[index]) {
                if (mid < j-1) return true;
                break;
            }
            else if (psum[j] - psum[mid] > a[index]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
    }    
    return false;
}

void solve() {
    cin >> t;
    while (t--) {
        int ans = 0;
        memset(psum, 0, sizeof(psum));
        cin >> n;
        for (int i=1; i<=n; i++) cin >> a[i];
        for (int i=1; i<=n; i++) psum[i] = psum[i-1] + a[i];
        for (int i=1; i<=n; i++) {
            bool ok = checkPerfect(1, i-1, i) | checkPerfect(i+1, n, i);
            if (ok) ans++;
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

