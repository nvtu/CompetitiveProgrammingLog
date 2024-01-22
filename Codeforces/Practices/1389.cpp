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

int t;
string s;

void solve() {
    cin >> t;
    while (t--) {
        cin >> s;
        int ans = INT_MAX;
        for (int i=0; i<10; i++) {
            for (int j=0; j<10; j++) {
                string tmp = "";
                tmp += (char)(i + '0');
                tmp += (char)(j + '0');
                int len = 0, p = 0;
                for (int k=0; k<s.length(); k++) {
                    if (s[k] == tmp[p]) {
                        len++;
                        p = 1 - p;
                    }
                }
                if (i != j && (len & 1)) len--;
                ans = min(ans, (int)s.length() - len);
            }
        }
        cout << ans << endl;
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