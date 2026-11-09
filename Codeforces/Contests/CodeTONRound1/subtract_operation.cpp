#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int SZ = int(2e5+5);


int t, n;
long long a[SZ], k;
map<long long, bool> s;


int main() {
    freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--) {
        s.clear();
        cin >> n >> k;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            s[a[i]] = true;
        }
        sort(a, a+n);
        bool hasAns = false;
        for (int i=0; i<n; i++) {
            if (s[a[i]+k]) {
                hasAns = true;
                break;
            }
        }
        cout << (hasAns ? "YES" : "NO") << endl;
    }
    return 0;
}

