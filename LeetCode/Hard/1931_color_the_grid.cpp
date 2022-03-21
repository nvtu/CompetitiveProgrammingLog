#include <iostream>
#include <queue>
using namespace std;

int colorTheGrid(int m, int n) {
    const int MOD = int(1e9+7);
    const int NUM_COLOR = 3;
    int ans = 0;
    long long f[m][n][NUM_COLOR];
    bool visit[m][n];
    queue<pair<int, int> > q;
    pair<int, int> direction[2] = {{0, 1}, {1, 0}};
    // Initialize
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            for (int k=0; k<NUM_COLOR; k++) {
                f[i][j][k] = 0;
                visit[m][n] = false;
            }
    f[0][0][0] = f[0][0][1] = f[0][0][2] = 1;
    visit[0][0] = true;
    if (n > 1) q.push({0, 1});
    if (m > 1) q.push({1, 0});
    while (!q.empty()) {
        pair<int, int> cell = q.front();
        q.pop();
        int i = cell.first, j = cell.second;
        visit[i][j] = true;
        // color this cell
        for (int c1=0; c1<NUM_COLOR; c1++){
            int c2=0, c3=0;
            for (; c2<NUM_COLOR; c2++) if (c2 != c1) break;
            for (; c3<NUM_COLOR; c3++) if (c3 != c1 && c3 != c2) break;
            if (i >= 1 && j >= 1) {
                f[i][j][c1] = (2 * (f[i-1][j][c2] + f[i-1][j][c3] + f[i][j-1][c2] + f[i][j-1][c3]) - (2 * f[i-1][j-1][c1] + 2 * f[i-1][j-1][c2] + 2 * f[i-1][j-1][c3]) + MOD) % MOD;
            }
            else if (i >= 1) f[i][j][c1] = (f[i-1][j][c2] + f[i-1][j][c3]) % MOD;
            else if (j >= 1) f[i][j][c1] = (f[i][j-1][c2] + f[i][j-1][c3]) % MOD;
        }
        // Add next cell to color
        for (int k=0; k<2; k++) {
            int nexti = i + direction[k].first, nextj = j + direction[k].second;
            if (visit[nexti][nextj] || nexti >= m || nextj >= n) continue;
            q.push({nexti, nextj});
        }
    }
    for (int i=0; i<NUM_COLOR; i++) ans = (ans + f[m-1][n-1][i]) %  MOD;
    return ans;
}


int main() {
//    freopen("input.txt", "r", stdin);
    int m, n;
    cin >> m >> n;
    cout << colorTheGrid(m, n) << endl;
    return 0;
}

