#include <bits/stdc++.h>
using namespace std;
const int SZ = 33000;

int t, n, f[SZ], a;

int main() {
    //freopen("input.txt", "r", stdin);
    for (int i=1; i<32768; i++) {
        f[i] = INT_MAX;
        for (int j=0; j<=15; j++) {
            int temp = (i+j) % 32768, cnt = j;
            while (temp > 0) {
                temp = (temp << 1) % 32768;
                cnt++;
            }
            f[i] = min(f[i], cnt);
        }
    }
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a;
        cout << f[a] << " ";
    }
    return 0;
}

