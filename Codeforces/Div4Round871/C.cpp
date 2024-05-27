#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(2e5+5);
const long long MOD = int(1e9+7);

int t, n, u;
string v;
map<string, int> r;

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> u >> v;
            if (r[v] == 0) r[v] = u;
            else r[v] = min(r[v], u);
        }
        int ans = -1;
        if (r["01"] > 0 && r["10"] > 0) ans = r["01"] + r["10"];
        if (r["11"] > 0) {
            if (ans != -1) ans = min(ans, r["11"]);
            else ans = r["11"];
        }
        cout << ans << endl; 
        r.clear();
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
