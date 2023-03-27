#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(3e5+5);
const long long MOD = int(1e9+7);

long long t, n, a[MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        long long sum = 0, mmax = LLONG_MIN, mmin = LLONG_MAX;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            mmax = max(mmax, a[i]);
            mmin = min(mmin, a[i]);
        }
        if (mmax - mmin <= sum) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;

        sort(a, a+n);
        int i = 0, j = n-1, k = 0; 
        long long psum = 0;

        while (i <= j) {
            if (psum >= 0) {
                psum += a[i];
                cout << a[i++] << " ";
            }
            else {
                psum += a[j];
                cout << a[j--] << " ";
            }
        }
        cout << endl;
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
