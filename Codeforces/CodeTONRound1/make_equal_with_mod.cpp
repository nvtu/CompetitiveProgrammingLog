#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int SZ = int(1e5+5);


int t, n, a[SZ];
map<int, bool> s;


int main() {
    freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--) {
        s.clear();
        cin >> n;
        bool hasOne = false;
        for (int i=0; i<n; i++) {
            cin >> a[i];

            if (a[i] == 1) hasOne = true;
            s[a[i]] = true;
        }
        bool equal = true;
        if (hasOne) {
            for (int i=0; i<n; i++) {
                if (a[i] < 2) continue;
                if (a[i]-1 >= 2 && s[a[i]-1] == false) {
                    a[i] = 1;
                }
            }
            for (int i=1; i<n; i++) {
                if (a[i] != a[i-1]) equal = false;
            }
        }
        cout << (equal ? "YES" : "NO") << endl;
    }
    return 0;
}

