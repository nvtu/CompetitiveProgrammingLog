#include <bits/stdc++.h>
using namespace std;
const int SZ = int(2e5+5);

int T, N;
long long A, B, x[SZ];

int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N >> A >> B;
        int c = 0;
        long long ans = 0;
        for (int i=0; i<N; i++) cin >> x[i];
        ans = x[0] * B;
        for (int i=1; i<N; i++) {
            long long costMoveCapitalConquer = A * (x[i-1] - c) + B * (x[i] - x[i-1]);
            long long costConquer = B * (x[i] - c);
            if (costConquer >= costMoveCapitalConquer) {
                ans += costMoveCapitalConquer;
                c = x[i-1];
            }
            else ans += costConquer;
        }
        cout << ans << endl;
    }
    return 0;
}

