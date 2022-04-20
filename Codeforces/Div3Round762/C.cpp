#include <bits/stdc++.h>
using namespace std;

int t;
long long a, s;

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> s;
        long long b = 0, mul = 1;
        while (s > 0 && a > 0) {
            int ad = a % 10,  sd = s % 10;
            s /= 10;
            if (ad > sd) sd = sd + s % 10 * 10, s /= 10;
            if (ad > sd || sd - ad > 9) break;
            else b = mul * (sd - ad) + b;
            mul *= 10;
            a /= 10;
        }
        b = mul * s + b;
        if (a > 0) cout << -1 << endl;
        else cout << b << endl;
    }
    return 0;
}

