#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e6 + 5);
const long long MOD = int(1e9 + 7);

int n, m, c[MAX_SIZE];
pair<int, int> minCost[MAX_SIZE];
long long dp[MAX_SIZE];
pair<int, int> a[MAX_SIZE];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i].first;
    int mmax = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
        a[i].second = a[i].first - a[i].second;
        mmax = max(mmax, a[i].first);
    }
    for (int i = 0; i < m; i++) cin >> c[i];
    for (int i = 0; i <= mmax; i++) minCost[i] = {INT_MAX, i};
    for (int i = 0; i < n; i++) {
        if (a[i].second <= minCost[a[i].first].first) {
            minCost[a[i].first] = {a[i].second, max(a[i].first, minCost[a[i].first].second)};
        }
    }
    for (int i = 1; i <= mmax; i++) {
        if (minCost[i].first > minCost[i - 1].first) {
            minCost[i] = minCost[i - 1];
        }
        if (minCost[i].first != INT_MAX) {
            long long k = (i - minCost[i].second + minCost[i].first) / minCost[i].first;
            dp[i] = (k << 1) + dp[i - k * minCost[i].first];
        } else
            dp[i] = dp[i - 1];
    }
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        if (c[i] > mmax) {
            long long k = (c[i] - minCost[mmax].second + minCost[mmax].first) / minCost[mmax].first;
            c[i] = c[i] - k * minCost[mmax].first;
            ans += (k << 1);
        }
        // cout << c[i] << " " << dp[c[i]] << endl;
        ans += dp[c[i]];
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
