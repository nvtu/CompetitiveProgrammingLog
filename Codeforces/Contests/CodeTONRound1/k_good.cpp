#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int SZ = int(1e5+5);

int t;
long long n;


int main() {
    freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n;
        long long x = n;
        while (x % 2 == 0) x /= 2;
        if (x == 1) cout << -1 << endl;
        else if (x < (long long)(3e9) && x*(x+1)/2 <= n) {
            cout << x << endl;
        }
        else cout << 2 * (n/x) << endl;
    }
    return 0;
}

