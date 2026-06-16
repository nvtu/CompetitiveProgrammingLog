#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n;

void solve() {
    cin >> n;
    double mmin = 1e9;
    int ans;
    vector<int> h(n + 1);
    h[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = n; i > 0; i--) {
        double v = 1, total_time = 0;
        for (int j = i; j > 0; j--) {
            total_time += (h[j] - h[j - 1]) / v;
            v += (h[j] - h[j - 1]);
        }
        if (total_time <= mmin) {
            mmin = total_time;
            ans = i;
        }
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