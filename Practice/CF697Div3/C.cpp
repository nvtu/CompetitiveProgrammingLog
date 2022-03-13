#include <bits/stdc++.h>
using namespace std;

const int MAX_ITEMS = int(2e5+5);
int t, n, m, k, a[MAX_ITEMS], b[MAX_ITEMS], cntPairBoy[MAX_ITEMS], cntPairGirl[MAX_ITEMS];

int main() {
    // freopen("C.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (int i=1; i<=n; i++) cntPairBoy[i] = 0;
        for (int i=1; i<=m; i++) cntPairGirl[i] = 0;
        for (int i=0; i<k; i++) {
            cin >> a[i];
            cntPairBoy[a[i]]++;
        }
        for (int i=0; i<k; i++) {
            cin >> b[i];
            cntPairGirl[b[i]]++;
        }
        long long ans = 0;
        for (int i=0; i<k; i++) {
            ans += 1LL * (k + 1 - cntPairBoy[a[i]] - cntPairGirl[b[i]]);
        }
        cout << ans / 2 << endl;
    }
    return 0;
}
