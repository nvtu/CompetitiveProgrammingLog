#include <bits/stdc++.h>
using namespace std;
 
 
long long n, t, k;
 
int main() {
    // freopen("test.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        long long  i = 2, temp = k;
        while (temp < n) temp = k * i, i++;
        k = temp;
        long long ans = k / n;
        if (k % n) ans++;
        cout << ans << endl;
    }
    return 0;
}