#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, a[MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> b[4];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 6 == 0) {
                b[3].push_back(a[i]);
            } else if (a[i] % 3 == 0) {
                b[2].push_back(a[i]);
            } else if (a[i] % 2 == 0) {
                b[0].push_back(a[i]);
            } else
                b[1].push_back(a[i]);
        }
        for (int i = 3; i >= 0; i--) {
            for (auto v : b[i]) {
                cout << v << " ";
            }
        }
        cout << endl;
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
