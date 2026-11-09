#include <bits/stdc++.h>
using namespace std;
const int SZ = int(5e5+5);

int t, n;
long long a[SZ];

int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=1; i<=n; i++) cin >> a[i];
        int j = 0, l = -1;
        bool update = false;
        long long ans = 0, sum = 0;
        while (j < n) {
            if (sum <= 0 && sum + a[j] >= 0) {
                l = j;
                update = true;
            }
            if (sum + a[j] >= 0) sum += a[j];
            else ans--;
        }
        cout << ans << endl;
    }
    return 0;
}

