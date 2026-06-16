#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n;
long long a[MAX_SIZE], k;
map<long long, long long> cnt;

void solve() {
    cin >> n >> k;
    long long total_damage = 0, ans = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        total_damage += (k - a[i]);
    }
    long long kills = 0;
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        kills += it->second;
        ans = min(ans, total_damage - kills * (k - it->first));
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
