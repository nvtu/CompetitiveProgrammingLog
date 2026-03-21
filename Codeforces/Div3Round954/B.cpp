#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e2 + 5);
const long long MOD = int(1e9 + 7);

int t, n, m, a[MAX_SIZE][MAX_SIZE];
const int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int mmax = 0;
                for (int k = 0; k < 4; k++) {
                    int x = i + d[k][0], y = j + d[k][1];
                    if (x >= 0 && x < n && y >= 0 && y < m) mmax = max(mmax, a[x][y]);
                }
                if (a[i][j] > mmax) a[i][j] = mmax;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
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
