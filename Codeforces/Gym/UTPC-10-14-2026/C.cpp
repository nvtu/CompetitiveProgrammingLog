#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int r, c, q;
string s[10], t;
bool visited[10][10];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool dfs(int x, int y, int p) {
    if (p >= t.size()) return true;
    visited[x][y] = true;
    bool found = false;
    for (int i = 0; i < 4 && !found; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < r && ny >= 0 && ny < c && !visited[nx][ny] && s[nx][ny] == t[p]) {
            found |= dfs(nx, ny, p + 1);
        }
    }
    visited[x][y] = false;
    return found;
}

void solve() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) cin >> s[i];
    memset(visited, false, sizeof(visited));
    cin >> q;
    while (q > 0) {
        q--;
        cin >> t;
        bool found = false;
        for (int i = 0; i < r && !found; i++) {
            for (int j = 0; j < c && !found; j++) {
                if (s[i][j] == t[0]) {
                    found = dfs(i, j, 1);
                }
            }
        }
        cout << (found ? "YES" : "NO") << endl;
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
