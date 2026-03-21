#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, a[MAX_SIZE], b[MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        int f = 0, s = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i] && a[i]) v.push_back(a[i]);
            if (a[i] > b[i])
                f += a[i];
            else if (a[i] < b[i])
                s += b[i];
        }
        for (auto x : v) {
            if (x > 0) {
                if (f > s)
                    s += x;
                else
                    f += x;
            } else {
                if (f > s)
                    f += x;
                else
                    s += x;
            }
        }
        cout << min(f, s) << endl;
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
