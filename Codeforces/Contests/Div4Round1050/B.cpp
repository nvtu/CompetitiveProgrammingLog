#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, m, x, y;

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> m >> x >> y;
        vector<int> a(n), b(m);
        for (auto& i : a) cin >> i;
        for (auto& i : b) cin >> i;
        cout << n + m << endl;
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
