#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int n, a[MAX_SIZE], visited[MAX_SIZE];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> cycles;
    bool origin_transformed = false;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        int cur = i;
        vector<int> nodes;
        while (!visited[cur]) {
            visited[cur] = true;
            nodes.push_back(cur);
            cur = a[cur];
        }
        cycles.push_back(nodes);
    }
    long long ans = 1, gcd = cycles[0].size();
    for (int i = 1; i < cycles.size(); i++) {
        gcd = __gcd(gcd, (long long)cycles[i].size());
    }
    for (auto cycle : cycles) {
        ans += (long long)cycle.size() / gcd - 1;
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
