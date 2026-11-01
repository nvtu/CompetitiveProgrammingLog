#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(3e5 + 5);
const long long MOD = int(1e9 + 7);

int n, m, a[MAX_SIZE][10];
set<int> s;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            s.insert(a[i][j]);
        }
    }
    vector<int> arr(s.begin(), s.end());
    int l = 0, r = arr.size() - 1;
    pair<int, int> ans = {-1, -1};
    while (l <= r) {
        int mid = (l + r) >> 1;
        int v = arr[mid];
        map<int, vector<int>> store;
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (int j = 0; j < m; j++) {
                if (a[i][j] >= v) {
                    mask |= 1 << j;
                }
            }
            store[mask].push_back(i);
        }
        bool ok = false;
        for (int i = 0; i < (1 << m) && !ok; i++) {
            for (int j = i; j < (1 << m) && !ok; j++) {
                if ((i | j) == (1 << m) - 1 && store[i].size() > 0 && store[j].size() > 0) {
                    ok = true;
                    ans = {store[i][0], store[j][0]};
                }
            }
        }
        if (ok) {
            l = mid + 1;
        } else
            r = mid - 1;
    }
    cout << ans.first + 1 << " " << ans.second + 1 << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
