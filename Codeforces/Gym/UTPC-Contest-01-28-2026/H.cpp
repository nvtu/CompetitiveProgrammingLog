#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n;
long long d[MAX_SIZE];

long long compute() {
    long long ans = -1, sum = 0, cur = 0;
    vector<long long> p;
    p.push_back(0);
    for (int i = 1; i <= n; i++) sum += d[i];
    for (int i = 1; i <= n; i++) {
        long long x = sum - cur;
        if (i >= 3) {
            if (cur >= 2 * x) {
                // guarantee prefix >= 2 * suffix
                // case: s2 s3 s1
                int j = lower_bound(p.begin(), p.end(), 2 * x) - p.begin();
                if (cur - p[j] >= 2 * p[j]) {
                    ans = max(ans, x);
                }
            }
            if (p[0] <= cur - 2 * x) {
                // case: s3 s2 s1
                int j = lower_bound(p.begin(), p.end(), cur - 2 * x + 1) - p.begin() - 1;
                if (p[j] >= 2 * (cur - p[j])) {
                    ans = max(ans, x);
                }
            }
            // case: s2 s1 s3
            int j = lower_bound(p.begin(), p.end(), (2 * cur + 2) / 3) - p.begin();
            if (j + 1 < i && x >= 2 * p[j]) {
                ans = max(ans, cur - p[j]);
            }
        }
        cur += d[i];
        p.push_back(cur);
    }
    return ans;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    long long ans = compute();
    reverse(d + 1, d + n + 1);
    ans = max(ans, compute());
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
