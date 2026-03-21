#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n, x, y;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (y >= 0)
            cout << "YES" << endl;
        else {
            if (y < -1)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
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
