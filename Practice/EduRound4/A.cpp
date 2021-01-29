#include <bits/stdc++.h>
using namespace std;

int n, p, q;
string s;

int main () {
    // freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> p >> q >> s;
    bool foundAns = false;
    for (int i=0; i * p <= n; i++) {
        if ((n - i * p) % q == 0) {
            foundAns = true;
            cout << i + (n - i * p) / q << endl;
            int j = 0;
            for (; j < i * p; j += p) cout << s.substr(j, p) << endl;
            for (; j < n; j += q) cout << s.substr(j, q) << endl;
            break;
        }
    }
    if (foundAns == false) cout << -1 << endl;
    return 0;
}