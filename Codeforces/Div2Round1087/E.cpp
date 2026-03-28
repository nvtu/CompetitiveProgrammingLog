#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, q, l, r;
string s;

vector<long long> z_function(string x) {
    int sz = x.size();
    vector<long long> z(sz, 0);
    long long mmax = 1;
    int L = 0, R = 0;
    z[0] = sz;
    for (int i = 1; i < sz; i++) {
        if (i > R) {
            L = R = i;
            while (R < sz && x[R - L] == x[R]) R++;
            z[i] = R - L;
            R--;
        } else {
            int k = i - L;
            if (z[k] < R - i + 1) {
                z[i] = z[k];
            } else {
                L = i;
                while (R < sz && x[R - L] == x[R]) R++;
                z[i] = R - L;
                R--;
            }
        }
    }
    return z;
}

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> q >> s;
        while (q--) {
            cin >> l >> r;
            vector<long long> z = z_function(s.substr(l - 1, r - l + 1));
            int sz = z.size();
            long long ans = 0;
            stack<int> b;
            for (int i = 1; i <= sz; i++) {
                int boundary = max(1LL * i, i + z[i - 1] - 1);
                if (z[i - 1] == 0) {
                    while (!b.empty() && i > b.top()) b.pop();
                } else {
                    b.push(boundary);
                }
                ans += 1LL * b.size();
            }
            cout << ans << endl;
        }
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