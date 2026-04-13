#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, m, a[MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> a[i];
        int max_subarray_cnt = 0, cnt = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1])
                cnt++;
            else {
                max_subarray_cnt = max(max_subarray_cnt, cnt);
                cnt = 1;
            }
        }
        max_subarray_cnt = max(max_subarray_cnt, cnt);
        if (max_subarray_cnt >= m) {
            cout << "NO" << endl;
        } else
            cout << "YES" << endl;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
