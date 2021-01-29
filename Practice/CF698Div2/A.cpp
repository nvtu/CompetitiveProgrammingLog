#include <bits/stdc++.h>
using namespace std;

const int MAX_ITEMS = int(1e2+5);
int t, n, a, cnt[MAX_ITEMS];


int main() {
    // freopen("test.txt", "r", stdin);
    cin >> t;
    while (t--) {
        fill(cnt, cnt+MAX_ITEMS, 0);
        cin >> n;
        int ans = 0;
        for (int i=0; i < n; i++) {
            cin >> a;
            cnt[a]++;
            ans = max(ans, cnt[a]);
        }
        cout << ans << endl;
    }
    return 0;
}