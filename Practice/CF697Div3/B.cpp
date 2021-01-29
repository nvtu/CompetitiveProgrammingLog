#include <bits/stdc++.h>
using namespace std;


int t, n;

int main() {
    // freopen("B.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n;
        bool foundResult = false;
        for (int i=0; i * 2020 <= n; i++) {
            if ((n - i * 2020) % 2021 == 0) {
                cout << "YES" << endl;
                foundResult = true;
                break;
            } 
        }
        if (!foundResult) cout << "NO" << endl;
    }
    return 0;
}
