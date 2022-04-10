#include <bits/stdc++.h>
using namespace std;
const int SZ = 30;

int t, n, a[SZ], b[SZ], c[SZ], d[SZ];

int main() {
//    freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];
        long long ans = 0;
        for (int i=1; i<n; i++) {
            long long sum1 = abs(a[i] - a[i-1]) + abs(b[i]-b[i-1]);
            long long sum2 = abs(b[i]-a[i-1]) + abs(a[i]-b[i-1]);
            if (sum1 > sum2) swap(a[i], b[i]);
            ans += min(sum1, sum2);
        }
        cout << ans << endl;
    }
    return 0;
}

