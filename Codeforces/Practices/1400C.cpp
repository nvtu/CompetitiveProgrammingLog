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

int t, x;
string s;

bool check(string s, string w) {
    for (int i=0; i<w.length(); i++) {
        if (i-x > 0 && w[i-x] == '1') {
            if (s[i] != '1') return false;
        }
        if (i+x < w.length() && w[i+x] == '1') {
            if (s[i] != '1') return false;
        }
    }
    return true;

}

void solve() {
    cin >> t;
    while (t--) {
        cin >> s >> x;
        string w = "";
        for (int i=0; i<s.length(); i++) w += "x";
        for (int i=1; i<=s.length(); i++) {
            if (s[i-1] == '0') {
                if (i > x) w[i-x-1] = '0';
                if (i+x <= s.length()) w[i+x-1] = '0';
            }
        }
        for (int i=0; i<w.length(); i++) {
            if (w[i] == 'x') w[i] = '1';
        }
        if (check(s, w)) cout << w << endl;
        else cout << -1 << endl;
    }
}


int main() {
    freopen("inp.txt", "r", stdin);

    //Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}