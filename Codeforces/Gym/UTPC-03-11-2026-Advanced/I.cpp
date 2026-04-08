#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int n, m, k, a[MAX_SIZE], b[MAX_SIZE];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    string ans = "";
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            ans += "A";
            i++;
        } else if (a[i] > b[j]) {
            ans += "B";
            j++;
        } else {
            int t = i, u = j, favor = 1;
            while (t < n && u < m && a[t] == b[u]) t++, u++;
            if (t == n)
                t--;
            else if (u == m) {
                u--, favor = 0;
            } else {
                if (a[t] < b[u]) favor = 0;
            }
            while (i <= t && j <= u) {
                if (a[i] < b[j])
                    ans += "A", i++;
                else if (a[i] > b[j])
                    ans += "B", j++;
                else {
                    if (favor == 0)
                        ans += "A", i++;
                    else
                        ans += "B", j++;
                }
            }
        }
    }
    while (i < n) ans += "A", i++;
    while (j < m) ans += "B", j++;
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
