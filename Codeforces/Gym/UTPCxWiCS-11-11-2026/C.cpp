#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n, m, k;

void solve() {
    cin >> n >> m >> k;
    vector<string> t(m), f(k), r(k);
    for (int i = 0; i < m; i++) cin >> t[i];
    for (int i = 0; i < k; i++) cin >> f[i];
    for (int i = 0; i < k; i++) cin >> r[i];
    reverse(t.begin(), t.end());
    reverse(f.begin(), f.end());
    reverse(r.begin(), r.end());

    vector<bitset<300>> tx(m), fz(k);
    vector<bitset<300>> ty(n), rz(k);
    vector<bitset<300>> rx(m), fy(n);

    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            if (t[x][y] == '#') {
                tx[x][y] = 1, ty[y][x] = 1;
            }
        }
    }
    for (int z = 0; z < k; z++) {
        for (int y = 0; y < n; y++) {
            if (f[z][y] == '#') {
                fz[z][y] = 1, fy[y][z] = 1;
            }
        }
    }
    for (int z = 0; z < k; z++) {
        for (int x = 0; x < m; x++) {
            if (r[z][x] == '#') {
                rz[z][x] = 1, rx[x][z] = 1;
            }
        }
    }
    long long ans = 0;
    // right view
    for (int z = 0; z < k; z++) {
        for (int x = 0; x < m; x++) {
            if (r[z][x] == '#') {
                int count = (tx[x] & fz[z]).count();
                if (count == 0) {
                    cout << -1 << endl;
                    return;
                }
                ans += count;
            }
        }
    }
    // top view
    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            if (t[x][y] == '#' && (rx[x] & fy[y]).none()) {
                cout << -1 << endl;
                return;
            }
        }
    }
    // front view
    for (int z = 0; z < k; z++) {
        for (int y = 0; y < n; y++) {
            if (f[z][y] == '#' && (rz[z] & ty[y]).none()) {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
