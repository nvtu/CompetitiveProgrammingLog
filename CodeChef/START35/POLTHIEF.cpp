#include <bits/stdc++.h>
using namespace std;

int T, X, Y;


int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> X >> Y;
        int ans = abs(Y - X);
        cout << ans << endl;
    }
    return 0;
}

