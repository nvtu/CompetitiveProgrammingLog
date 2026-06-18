#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n;
string s;

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int open = 0, close = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                open++;
            else
                close++;
        }
        cout << (open == close ? "YES" : "NO") << endl;
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
