#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e2 + 5);
const long long MOD = int(1e9 + 7);

int n, m, a[MAX_SIZE];
vector<int> edge[MAX_SIZE];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        int _gcd = gcd(u, v);
        if (_gcd > 1) {
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
