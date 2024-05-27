#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

int t;
string s;
string u = "codeforces";

void solve() {
    cin >> t;
    while (t--) {
        cin >> s;
        int ans = 0;
        for (int i=0; i<s.size(); i++) { 
            if (s[i] != u[i]) ans++;
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