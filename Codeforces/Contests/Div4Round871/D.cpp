#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);


int t, n, m;

bool isPowerOfTwo(int x) {
    return (x && !(x & (x-1)));
}

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int cnt = 0;
        if (m <= n) {
            while (n % 3 == 0) {
                n /= 3;
                cnt++;
            }
            int cntm = 0;
            while (m % 3 == 0) {
                m /= 3; 
                cntm++;
            }
            if (cntm <= cnt) {
                cntm = 0;
                while (m % 2 == 0) {
                    m /= 2;
                    cntm++;
                }
                if (cntm <= ()) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
        else cout << "NO" << endl;
    }
}


int main() {
    freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
