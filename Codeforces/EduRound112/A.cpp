#include <bits/stdc++.h>
using namespace std;

int T;
long long N;

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        if (N & 1) N++;
        N >>= 1;
        if (N < 3) N = 3;
        long long ans = 0;
        if (N % 3 == 0) ans = 15 * (N / 3);
        else {
            ans = 15 * ((N - 3) / 3) + (N % 3 == 1 ? 20 : 25);
        }
        cout << ans << endl;
    }
    return 0;
}

