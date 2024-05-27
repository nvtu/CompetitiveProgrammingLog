#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

long long t, n, a[MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) cin >> a[i];
        vector<long long> v;
        for (int i=0; i<n/2; i++) v.push_back(a[i] - a[n-1-i]);
        long long x = 0;
        for (auto i: v) x = __gcd(x, i);
        if (x < 0) x = -x;
        cout << x << endl;
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
