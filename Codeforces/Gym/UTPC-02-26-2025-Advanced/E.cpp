#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int GRID_MAX_SIZE = int(1e3 + 5);
const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int n, q, d[MAX_SIZE];
double cnt[sqr(GRID_MAX_SIZE)];
string s[GRID_MAX_SIZE];
queue<pair<pair<int, int>, int>> qu;
bool visited[GRID_MAX_SIZE][GRID_MAX_SIZE];

void solve() {
    cin >> n >> q;
    memset(visited, false, sizeof(visited));
    memset(cnt, 0, sizeof(cnt));
    double empty = 0;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < q; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i].size(); j++) {
            if (s[i][j] == 'E') {
                visited[i][j] = true;
                qu.push({{i, j}, 1});
            } else if (s[i][j] == '.')
                empty++;
        }
    }
    int r = 0;
    while (!qu.empty()) {
        auto [coor, count] = qu.front();
        auto [x, y] = coor;
        qu.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                if (!visited[nx][ny] && s[nx][ny] == '.') {
                    visited[nx][ny] = true;
                    qu.push({{nx, ny}, count + 1});
                    cnt[count + 1]++;
                }
            }
        }
    }
    for (int i = 1; i <= sqr(n); i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < q; i++) {
        cout << fixed << setprecision(8) << cnt[d[i]] / empty << endl;
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
