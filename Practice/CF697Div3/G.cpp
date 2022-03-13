#include <bits/stdc++.h>
using namespace std;

const int MAX_ITEMS = int(2e5+5);
int t, n, a[MAX_ITEMS], dp[MAX_ITEMS];
map<int, int> cnt;



int main() {
    freopen("G.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n;
        cnt.clear();
        fill(dp, dp + MAX_ITEMS, 0);
        for (int i=0; i<n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        for (int i=1; i<MAX_ITEMS; i++) {
            dp[i] += cnt[i];
            for (int j=2*i; j < MAX_ITEMS; j += i) dp[j] = max(dp[j], dp[i]);
        }
        cout << (n - *max_element(dp, dp + MAX_ITEMS)) << endl;
    }
    return 0;
}
