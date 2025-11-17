#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);
int t, n, a[MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        bool even = false, odd = false;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] & 1)
                odd = true;
            else
                even = true;
        }
        if (odd & even) sort(a, a + n);
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
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
