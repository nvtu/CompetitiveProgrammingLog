#include <bits/stdc++.h>
using namespace std;
const int SZ = int(3e5+5);

int t, n, h[SZ];

long long solve(long long mmax) {
    long long ans = LLONG_MAX, even = 0, odd = 0;
    for (int i=0; i<n; i++) {
        long long diff = mmax - h[i];
        even += diff / 2;
        odd += diff % 2;
    }
    if (odd > 0 && odd > even) ans = min(ans, 2 * (odd - 1) + 1);
    if (even >= odd) {
        long long x = (even - odd + 2) / 3; 
        long long y = (even - odd) / 3;
        if (odd + 2 * x > even - x) 
            ans = min(ans, 2 * (odd + 2 * x - 1) + 1);
        else ans = min(ans, 2 * (even - x));
        ans = min(ans, 2 * (even - y));
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n;
        long long mmax = 0;
        for (int i=0; i<n; i++) {
            cin >> h[i];
            mmax = max(mmax, (long long) h[i]);
        }
        cout << min(solve(mmax), solve(mmax+1)) << endl;    
    }
    return 0;
}

