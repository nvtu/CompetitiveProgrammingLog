#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(3e5+5);
const long long MOD = int(1e9+7);

long long t, n, m, x;
vector<long long> c[MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> x;
                c[j].push_back(x);
            }
        }

        long long ans = 0;
        for (int i=0; i<m; i++) {
            sort(c[i].begin(), c[i].end());
            long long t = n-1, u = 0;
            for (auto k: c[i]) {
                ans += u * k - t * k;
                u++, t--;
            }
        }
        cout << ans << endl;
        for (int i=0; i<m; i++) c[i].clear();
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
