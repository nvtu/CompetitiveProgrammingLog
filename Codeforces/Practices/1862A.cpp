#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, m;
string s[25];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> s[i];
        int index = 4;
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (s[i][j] == 'v' && index == 4) {
                    index--;
                    break;
                } else if (s[i][j] == 'i' && index == 3) {
                    index--;
                    break;
                } else if (s[i][j] == 'k' && index == 2) {
                    index--;
                    break;
                } else if (s[i][j] == 'a' && index == 1) {
                    index--;
                    break;
                }
            }
        }
        cout << (index == 0 ? "YES" : "NO") << endl;
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
