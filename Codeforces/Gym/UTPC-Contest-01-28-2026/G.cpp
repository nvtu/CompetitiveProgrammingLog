#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n, m, k;
map<int, vector<int>> grouped_obs;

void solve() {
    cin >> n >> m >> k;
    set<int> rows;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        rows.insert(x);
        grouped_obs[x].push_back(y);
    }
    rows.insert(n);
    vector<pair<int, int>> intervals = {{1, m}};

    int prev = 1;
    for (auto it = rows.begin(); it != rows.end(); it++) {
        int x = *it;
        vector<int> cols = grouped_obs[x];
        sort(cols.begin(), cols.end());
        int d = x - prev;
        // Expand the column intervals at row x
        vector<pair<int, int>> new_intervals;
        for (auto [l, r] : intervals) {
            l = max(1, l - d);
            r = min(m, r + d);
            new_intervals.push_back({l, r});
        }
        // Split the intervals based on the obstacles
        vector<pair<int, int>> splits;
        for (auto [l, r] : new_intervals) {
            int cur = l;
            for (int c : cols) {
                if (c < l || c > r) continue;
                if (cur <= c - 1) {
                    splits.push_back({cur, c - 1});
                }
                cur = c + 1;
            }
            if (cur <= r) {
                splits.push_back({cur, r});
            }
        }
        // Merge overlapping intervals
        vector<pair<int, int>> merged;
        for (auto [l, r] : splits) {
            if (merged.empty() || merged.back().second < l - 1) {
                merged.push_back({l, r});
            } else {
                merged.back().second = max(merged.back().second, r);
            }
        }
        intervals = merged;
        // Set the current row as the previous to continue the process
        prev = x;
    }
    vector<int> ans;
    for (auto [l, r] : intervals) {
        for (int i = l; i <= r; i++) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (auto c : ans) cout << c << " ";
}

int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
