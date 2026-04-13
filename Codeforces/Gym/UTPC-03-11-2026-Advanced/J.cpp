#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int n, a[MAX_SIZE], p[MAX_SIZE], sz[MAX_SIZE];
vector<int> d[int(1e6 + 6)];
map<int, int> ms;
map<int, int> cnt;
set<int> s;
long long ans[2];

int find_root(int u) {
    if (u != p[u]) {
        p[u] = find_root(p[u]);
    }
    return p[u];
}

void dsu(int u, int v) {
    int rootu = find_root(u);
    int rootv = find_root(v);
    if (rootu == rootv) return;
    if (sz[rootu] > sz[rootv]) swap(rootu, rootv);
    p[rootu] = p[rootv];
    sz[rootv] += sz[rootu];
}

void solve() {
    cin >> n;
    ans[0] = 0;
    ans[1] = LLONG_MAX;
    int mmax = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mmax = max(mmax, a[i]);
        cnt[a[i]]++;
        s.insert(a[i]);
    }
    int m = 1;
    for (auto it = s.begin(); it != s.end(); it++, m++) {
        int v = *it;
        ms[v] = m;
        p[ms[v]] = ms[v];
        sz[ms[v]] = 1;
        ans[0] += 1LL * v * (cnt[v] - 1);
        ans[1] = min(ans[1], 1LL * v * v);
        for (int i = 1; i <= sqrt(v); i++) {
            if (v % i == 0) {
                d[i].push_back(v);
                if (v / i != i) {
                    d[v / i].push_back(v);
                }
            }
        }
    }
    for (int i = mmax; i > 0; i--) {
        if (d[i].size() > 0) {
            for (int j = 1; j < d[i].size(); j++) {
                int u = ms[d[i][0]];
                int parent = find_root(u);
                int v = ms[d[i][j]];
                int cur_parent = find_root(v);
                if (parent != cur_parent) {
                    dsu(u, v);
                    ans[1] = min(ans[1], 1LL * i * i);
                    ans[0] += 1LL * i;
                }
            }
        }
    }
    for (auto v : ans) cout << v << " ";
}

int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
