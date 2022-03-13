#include <bits/stdc++.h>
using namespace std;


int t;
long long n;

int main() {
    // freopen("A.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n;
        while (n > 1 && n%2 == 0) n >>= 1;
        if (n > 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}