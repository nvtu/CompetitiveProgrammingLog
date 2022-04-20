#include <bits/stdc++.h>
using namespace std;
const int SZ = int(1e5+5);

long long n, m, t, a[SZ];

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        string ans = "NO";
        cin >> n >> m;
        for (int i=0; i<n; i++) cin >> a[i];
        sort(a, a+n);
        long long rchair = n + a[n-1];
        for (int i=1; i<n; i++) rchair += max(a[i], a[i-1]);
        if (rchair <= m) ans = "YES";
        cout << ans << endl;
    }
    return 0;
}

