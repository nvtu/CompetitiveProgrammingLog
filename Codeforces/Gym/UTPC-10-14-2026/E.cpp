#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

long long n, T, m, k, t[MAX_SIZE], b[MAX_SIZE], tt[MAX_SIZE];
vector<int> edge[MAX_SIZE];

long long dfs(int u) {
    long long mmax = 0;
    for (auto v : edge[u]) {
        mmax = max(mmax, dfs(v));
    }
    mmax += tt[u];
    return mmax;
}

void solve() {
    cin >> n >> T;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> k;
            edge[i].push_back(k);
        }
    }
    long long l = 1, r = int(2e9), ans = -1;
    while (l <= r) {
        m = (l + r) >> 1;
        // Check
        for (int i = 1; i <= n; i++) {
            tt[i] = b[i] ? t[i] / m : t[i];
        }
        long long total_time = dfs(1);
        if (total_time <= T) {
            ans = m;
            r = m - 1;
        } else
            l = m + 1;
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
