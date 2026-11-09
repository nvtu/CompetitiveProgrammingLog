#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, k, x;

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> ki(n), relevant;
        vector<int> ans;
        int max_size = 0;
        for (int i = 0; i < n; i++) {
            cin >> k;
            ki[i].resize(k);
            max_size = max(max_size, k);
            for (int j = 0; j < k; j++) {
                cin >> ki[i][j];
                if (relevant.size() == j) relevant.push_back({});
                relevant[j].push_back(i);
            }
        }
        vector<int> lex_min(max_size), rank(n, -1);
        for (int i = max_size - 1; i >= 0; i--) {
            vector<array<int, 3>> cur;
            for (auto j : relevant[i]) {
                cur.push_back({ki[j][i], rank[j], j});
            }
            sort(cur.begin(), cur.end());
            lex_min[i] = cur[0][2];
            int updated_rank = 0;
            for (auto j : cur) rank[j[2]] = updated_rank++;
        }
        while (ans.size() < max_size) {
            int cur = ans.size();
            int min_row_index = lex_min[cur];
            for (int i = cur; i < ki[min_row_index].size(); i++) {
                ans.push_back(ki[min_row_index][i]);
            }
        }
        // Print answer
        for (auto v : ans) cout << v << " ";
        cout << endl;
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
