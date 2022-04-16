#include <bits/stdc++.h>
using namespace std;

int T;
long long A, B;

long long gcd(long long x, long long y) {
    return !y ? x : gcd(y, x % y);
}

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> A >> B;
        if (min(A, B) <= 1) cout << -1 << endl;
        else {

            if (gcd(A, B) > 1) cout << 0 << endl; 
            else cout << 1 << endl;
        }
    }
    return 0;
}

