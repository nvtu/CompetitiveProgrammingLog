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
string s;
vector<int> stk[2];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> s;
        vector<int> ans(n, 1);
        stk[0].clear();
        stk[1].clear();
        int index = 0;
        for (int i=0; i<n; i++) {
            int cur = (int)(s[i] - '0');
            int prev = 1 - cur;
            if (stk[prev].size() > 0) {
                int head = stk[prev].back();
                stk[prev].pop_back();
                stk[cur].push_back(i);
                ans[i] = ans[head];
            }
            else {
                stk[cur].push_back(i);
                ans[i] = ++index;
            }
        }
        cout << index << endl;
        for (int i=0; i<n; i++)
            cout << ans[i] << " ";
        cout << endl;
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