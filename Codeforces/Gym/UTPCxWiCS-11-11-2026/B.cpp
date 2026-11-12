#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int n, m, u[MAX_SIZE], v[MAX_SIZE];
char c[MAX_SIZE];
bool is_good[MAX_SIZE];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> c[i];
        if (c[i] == 'G') {
            is_good[u[i]] = is_good[v[i]] = true;
        }
    }
    for (int i = 0; i < m; i++) {
        if (c[i] == 'B' && is_good[u[i]] && is_good[v[i]]) {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << (is_good[i] ? 'G' : 'B') << endl;
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
