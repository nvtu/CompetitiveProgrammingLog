#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

long long t, n, b[MAX_SIZE];
long long preMax[MAX_SIZE], sufMax[MAX_SIZE];


void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=1; i<=n; i++) cin >> b[i];
        preMax[0] = 0, sufMax[n+1] = LLONG_MIN;
        for (int i=1; i<=n; i++) preMax[i] = max(preMax[i-1], b[i] + i);
        for (int i=n; i>=1; i--) sufMax[i] = max(sufMax[i+1], b[i] - i);
        long long ans = 0;
        for (int i=2; i<n; i++) {
            ans = max(ans, preMax[i-1] + sufMax[i+1] + b[i]);
        }
        cout << ans << endl;
    }
}


int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
