#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, k, x;

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<int, vector<int>>> k(n);
        int max_size = 0;
        for (int i = 0; i < n; i++) {
            cin >> k[i].first;
            max_size = max(max_size, k[i].first);
            for (int j = 0; j < k[i].first; j++) {
                cin >> x;
                k[i].second.push_back(x);
            }
        }
        sort(k.begin(), k.end());
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
