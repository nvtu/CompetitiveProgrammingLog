#include <bits/stdc++.h>
using namespace std;
 
int q, t, d, a;
 
bool checkHasDigit(int n, int digit) {
    while (n > 0) {
        int d = n % 10;
        if (d == digit) return true;
        n /= 10;
    }
    return false;
}
 
 
int main() {
    // freopen("test.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> q >> d;
        for (int i=0; i<q; i++) {
            string ans = "YES";
            cin >> a;
            if (a / d < 10) {
                while (a > 0) {
                    if (checkHasDigit(a, d)) break;
                    a -= d;
                }
                if (a <= 0) ans = "NO";
            }
            cout << ans << endl;
        }
    }
}