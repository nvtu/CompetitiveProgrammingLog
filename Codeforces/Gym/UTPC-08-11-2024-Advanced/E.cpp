#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);
const double EPS = 1e-6;

int n, m;

bool match_melody(vector<int> s, vector<int> a) {
    map<int, multiset<int>> g;
    for (int i = 0; i < m; i++) {
        if (i > 0) {
            g[a[i - 1]].insert(a[i]);
        }
    }
    if (m > 1) {
        g[a[m - 1]].insert(a[0]);
    }
    for (int i = 0; i < m; i++) {
        if (i == 0) {
            if (g[s[i]].size() == 0) {
                return false;
            }
        } else {
            if (g[s[i - 1]].size() == 0) {
                return false;
            }
            multiset<int>::iterator it = g[s[i - 1]].find(s[i]);
            if (it == g[s[i - 1]].end()) {
                return false;
            } else {
                g[s[i - 1]].erase(it);
            }
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    vector<int> s(m);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (match_melody(s, a[i])) {
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    // freopen("inp.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}