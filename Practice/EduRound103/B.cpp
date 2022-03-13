#include <bits/stdc++.h>
using namespace std;


const int MAX_ITEMS = int(1e2+3);
int n, t;
long long p[MAX_ITEMS], k;


int main() {
    // freopen("test.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i=0; i<n; i++) cin >> p[i];
        long long ans = 0, sum = p[0];
        for (int i=1; i<n; i++) {
            long long temp = sum * k;
            if (p[i] * 100 > temp) {
                long long delta = (p[i] * 100 - temp + k - 1) / k;
                ans += delta;
                sum += delta; 
            }
            sum += p[i];
        }
        cout << ans << endl;
    }
    return 0;
}