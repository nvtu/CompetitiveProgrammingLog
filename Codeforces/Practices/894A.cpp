#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

string s;
int dp1[105];  // Keep track of Q

void solve() {
    cin >> s;
    int n = int(s.size()), ans = 0;
    if (s[0] == 'Q') dp1[0] = 1;
    dp1[1] = dp1[0];
    if (s[1] == 'Q')
        dp1[1]++;
    for (int i = 2; i < n; i++) {
        dp1[i] = dp1[i - 1];
        if (s[i] == 'Q') {
            for (int j = 1; j < i; j++) {
                if (s[j] == 'A') {
                    ans += dp1[j - 1];
                }
            }
            dp1[i]++;
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
