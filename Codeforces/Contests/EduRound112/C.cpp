#include <bits/stdc++.h>
using namespace std;
const int SZ = int(1e5+5);

int T, M, a[2][SZ];

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> M;
        for (int i=0; i<2; i++) {
            for (int j=0; j<M; j++) cin >> a[i][j];
        }
        int sum1 = 0, sum2 = 0, ans = INT_MAX;
        for (int i=0; i<M; i++) sum1 += a[0][i];
        for (int i=0; i<M; i++) {
            sum1 -= a[0][i];
            ans = min(ans, max(sum1, sum2));
            sum2 += a[1][i];
        }
        cout << ans << endl;
    }
    return 0;
}

