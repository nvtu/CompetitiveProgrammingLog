#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

long long n, a, b, p[MAX_SIZE], sa[MAX_SIZE], sb[MAX_SIZE], ans, treex[MAX_SIZE], treey[MAX_SIZE];
set<long long> x, y;
map<long long, int> mx, my;

void update(long long tree[], long long idx, long long max_idx, long long val) {
    while (idx <= max_idx) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

long long query(const long long tree[], int idx) {
    long long sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void solve() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sa[i] = sa[i - 1] + p[i] - a;
        sb[i] = sb[i - 1] + p[i] - b;
        x.insert(sa[i]);
        y.insert(sb[i]);
    }
    x.insert(0);
    y.insert(0);

    int cntx = x.size();
    int cnty = y.size();
    int r = 1;
    for (long long v : x) mx[v] = r++;
    r = 1;
    for (long long v : y) my[v] = r++;
    for (int i = 0; i <= n; i++) {
        long long cnt = query(treex, mx[sa[i]]) - query(treey, my[sb[i]] - 1);
        update(treex, mx[sa[i]], cntx, 1);
        update(treey, my[sb[i]], cnty, 1);
        ans += cnt;
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
