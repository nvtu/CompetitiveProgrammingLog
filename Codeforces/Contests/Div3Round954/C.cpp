#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, m, ind[MAX_SIZE];
string s, c;

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> m >> s;
        for (int i = 0; i < m; i++) cin >> ind[i];
        cin >> c;
        sort(ind, ind + m);
        sort(c.begin(), c.end());
        string temp = c;
        int l = 0, r = m - 1;
        for (int i = 1; i < m; i++) {
            if (ind[i] == ind[i - 1]) {
                temp[i - 1] = c[r--];
            } else {
                temp[i - 1] = c[l++];
            }
        }
        temp[m - 1] = c[l];
        for (int i = 0; i < m; i++) {
            s[ind[i] - 1] = temp[i];
        }
        cout << s << endl;
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
