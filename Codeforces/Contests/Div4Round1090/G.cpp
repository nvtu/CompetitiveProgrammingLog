#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = 676767677;

long long t, n, m, b[MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> b[i];
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<bool> sit(n, false);
        vector<long long> c(n, 0), cnt(m + 1, 0);
        long long ans = 1;
        for (int i = 0; i < n; i++) {
            cnt[b[i]]++;
            if (b[i] == 0) {
                pq.push({b[i], i});
                sit[i] = true;
                c[i] = 1;
            }
        }
        for (long long time = 0; time < m; time++) {
            if (time > 0) cnt[time] += cnt[time - 1];
            while (!pq.empty()) {
                auto [v, i] = pq.top();
                if (v != time) break;
                pq.pop();
                if (i - 1 >= 0 && !sit[i - 1] && b[i - 1] > time) {
                    pq.push({b[i - 1], i - 1});
                    sit[i - 1] = true;
                    c[i - 1] = cnt[b[i - 1] - 1];
                }
                if (i + 1 < n && !sit[i + 1] && b[i + 1] > time) {
                    pq.push({b[i + 1], i + 1});
                    sit[i + 1] = true;
                    c[i + 1] = cnt[b[i + 1] - 1];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            ans = (ans * c[i]) % MOD;
        }
        cout << ans << endl;
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}