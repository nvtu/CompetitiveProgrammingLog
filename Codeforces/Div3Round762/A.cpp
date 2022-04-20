#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        int sz = s.size();
        if (sz % 2) cout << "NO" << endl;
        else {
            bool ok = false;
            for (int i=0; i<sz/2; i++) {
                if (s[i] != s[sz/2+i]) {
                    ok = true;
                    break;
                }
            }
            cout << (ok ? "NO" : "YES") << endl;
        }
    }
    return 0;
}

