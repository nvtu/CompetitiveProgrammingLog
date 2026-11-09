#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstdlib>
#include <set>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);
const double EPS = 1e-6;

int t, n;

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        string ans = "";
        string s[2];
        cin >> s[0] >> s[1];
        for (int i=0; i<n; i++) {
            if (i == n-1) {
                ans += s[0][i];
                ans += s[1][i];
            }
            else {
                ans += s[0][i];
                if (s[0][i+1] > s[1][i]) {
                    for (int j=i; j<n; j++) ans += s[1][j];
                    break;
                }
            }
        }
        int cnt = 1;
        for (int i=0; i<n; i++) {
            if (i < n-1) {
                if (s[0][i+1] == s[1][i]) cnt++;
                else if (s[0][i+1] < s[1][i]) cnt = 1;
                else if (s[0][i+1] > s[1][i]) break;
            }
        }
        cout << ans << endl << cnt << endl;
    }
}


int main() {
    // freopen("inp.txt", "r", stdin);

    //Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}