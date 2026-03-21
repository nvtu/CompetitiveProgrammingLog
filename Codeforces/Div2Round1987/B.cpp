#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);
int t, n;
long long a[MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long> d;
        for (int i = 0; i < n; i++) cin >> a[i];
        d.push_back(0);
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                d.push_back(a[i - 1] - a[i]);
                a[i] = a[i - 1];
            }
        }
        sort(d.begin(), d.end());
        long long ans = 0;
        for (int i = 1; i < d.size(); i++) {
            if (d[i] != d[i - 1]) {
                ans += (d[i] - d[i - 1]) * (d.size() - i + 1);
            }
        }
        cout << ans << endl;
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
