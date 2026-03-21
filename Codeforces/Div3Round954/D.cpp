#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n;
string s;

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int ans = INT_MAX;
        if (n == 2) {
            ans = (s[0] - '0') * 10 + (s[1] - '0');
        } else if (n == 3) {
            ans = min((s[0] - '0') * 10 + (s[1] - '0') + (s[2] - '0'), (s[0] - '0') + (s[1] - '0') * 10 + (s[2] - '0'));
            ans = min(ans, ((s[0] - '0') * 10 + (s[1] - '0')) * (s[2] - '0'));
            ans = min(ans, (s[0] - '0') * ((s[1] - '0') * 10 + (s[2] - '0')));
        } else {
            int zeroInd = -1;
            for (int i = 0; i < n; i++) {
                if (s[i] == '0') zeroInd = i;
            }
            if (zeroInd == -1) {
                for (int i = 0; i < n - 1; i++) {
                    int temp = 0;
                    for (int j = 0; j < n; j++) {
                        if (j == i) {
                            temp += (s[j] - '0') * 10 + (s[j + 1] - '0');
                            j++;
                        } else if (s[j] == '1')
                            continue;
                        else
                            temp += s[j] - '0';
                    }
                    ans = min(ans, temp);
                }
            } else
                ans = 0;
        }
        cout << ans << endl;
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
