#include <bits/stdc++.h>
using namespace std;
const int SZ = int(1e5+5);

long long T, N, X, A[SZ];

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> X;
        for (int i=0; i<N; i++) cin >> A[i];
        long long ans = 0;
        for (int i=0; i<N; i++) {
            ans = max(ans, (X + A[i] - 1) / A[i]);
        }
        ans = max(ans, N);
        cout << ans << endl;
    }
    return 0;
}

