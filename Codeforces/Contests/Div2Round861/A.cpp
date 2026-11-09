#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

int t, l, r;

int luckyNumber(int x) {
    int mmax = 0, mmin = 10;
    while (x > 0) {
        mmax = max(mmax, x%10); 
        mmin = min(mmin, x%10);
        x /= 10;
    }
    return mmax - mmin;
}

void solve() {
    cin >> t;
    while (t--) {
        cin >> l >> r;
        int range = min((r-l+1), 1000);
        int mmax = 0, ans = -1;
        for (int i=0; i<range; i++) {
            int lucky = luckyNumber(l+i); 
            if (lucky >= mmax) {
                mmax = lucky;
                ans = l+i;
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
