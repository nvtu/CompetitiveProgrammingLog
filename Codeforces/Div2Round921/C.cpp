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

int t, n, k, m;
string s, ans = "";
vector<int> p[30];


int find_next_pos(int i, int val) {
    int l = 0, r = int(p[i].size()) - 1, pos = -1;
    while (l <= r) {
        int mid = (l+r) >> 1;
        if (p[i][mid] <= val) l = mid+1;
        else {
            pos = p[i][mid];
            r = mid-1;
        }
    }
    return pos;
}

bool check(string t) {
    int val = t[0] - 'a';
    if (p[val].size() == 0) return false;
    int pos = p[val][0];
    for (int i=1; i<t.length(); i++) {
        int val = t[i] - 'a';
        pos = find_next_pos(val, pos);
        if (pos == -1) return false; 
    }
    return true;
}

void construct(string t, int pos) {
    if (ans != "") return;
    if (pos == n) {
        if (!check(t)) ans = t;
        return;
    }
    for (int i=0; i<k && ans==""; i++) {
        t[pos] = char(i + 'a');
        construct(t, pos+1);
    }
}

void solve() {
    cin >> t;
    while (t--) {
        for (int i=0; i<30; i++) p[i].clear();
        ans = "";
        cin >> n >> k >> m >> s;
        for (int i=0; i<s.length(); i++) {
            int pos = s[i] - 'a';
            p[pos].push_back(i);
        }
        string temp = "";
        for (int i=0; i<n; i++) temp += "a";
        construct(temp, 0);
        if (ans == "") cout << "YES" << endl;
        else cout << "NO" << endl << ans << endl;
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