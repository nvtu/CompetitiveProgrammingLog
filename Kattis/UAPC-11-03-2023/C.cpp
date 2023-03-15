#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

string s;

string removeDuplicate(string t) {
    string res = "";
    int len = t.size();
    res += t[0];
    for (int i=1; i<len; i++) {
        if (t[i] != t[i-1]) res += t[i];
    }
    return res;
}


void solve() {
    while (cin >> s) {
        cout << removeDuplicate(s) << " ";
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
