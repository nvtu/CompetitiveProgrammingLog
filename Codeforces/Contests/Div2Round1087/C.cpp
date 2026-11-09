#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);
int t, n, res;

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0;
        for (int i = 1; i < 2 * n - 3; i += 2) {
            cout << "? " << i << " " << i + 1 << endl;
            cout.flush();
            cin >> res;
            if (res == 1) {
                ans = i;
                break;
            }
        }
        if (ans == 0) {
            for (int i = 2 * n - 2; i < 2 * n; i++) {
                cout << "? " << 2 * n - 3 << " " << i << endl;
                cout.flush();
                cin >> res;
                if (res == 1) {
                    ans = i;
                    break;
                }
            }
        }
        if (ans == 0) {
            cout << "? " << 2 * n - 2 << " " << 2 * n - 1 << endl;
            cout.flush();
            cin >> res;
            if (res == 1) {
                ans = 2 * n - 1;
            }
        }
        if (ans == 0) {
            ans = 2 * n;
        }
        cout << "! " << ans << endl;
        cout.flush();
    }
}

int main() {
    // freopen("input.txt",2 "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
