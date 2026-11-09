#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

int t, n, a[105], b[105];

bool check() {
    for (int i=0; i<n-1; i++) {
        if (a[i] > a[n-1]) {
            if (b[i] > a[n-1]) return false;
            else swap(b[i], a[i]);
        }
    }
    for (int i=0; i<n-1; i++) {
        if (b[i] > b[n-1]) return false;
    }
    return true;
}


void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        int aMax = 0, bMax = 0;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            aMax = max(aMax, a[i]);
        }
        for (int i=0; i<n; i++) {
            cin >> b[i];
            bMax = max(bMax, b[i]);
        }
        bool ok = check();
        swap(a[n-1], b[n-1]);
        ok = ok || check();
        cout << (ok ? "Yes" : "No") << endl;
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
