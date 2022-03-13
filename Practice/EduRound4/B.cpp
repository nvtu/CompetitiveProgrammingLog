#include <bits/stdc++.h>
using namespace std;

const int MAX_ITEMS = int(2e5+5);
int n, pos[MAX_ITEMS], f;
long long ans = 0;

int main () {
    // freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> f;
        pos[f] = i+1;
    }
    if (n == 1) ans = 1LL * (f - 1);
    for (int i=2; i <= n; i++) ans += 1LL * abs(pos[i] - pos[i-1]);
    cout << ans << endl;
    return 0;
}