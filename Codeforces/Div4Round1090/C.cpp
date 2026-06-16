#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n;

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        int a[3] = {1, 3 * n - 1, 3 * n};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) cout << a[j] << " ";
            a[0]++;
            a[1] -= 2;
            a[2] -= 2;
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
