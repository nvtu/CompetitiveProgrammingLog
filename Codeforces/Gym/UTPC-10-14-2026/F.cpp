#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n;
string s;
vector<pair<int, int>> ans;

void hanoi_tower(int n, int src, int dest) {
    if (n == 0) return;
    int aux = 6 - src - dest;
    hanoi_tower(n - 1, src, aux);
    ans.push_back({src, dest});
    hanoi_tower(n - 1, aux, dest);
}

void build_tower(int k, int p) {
    if (k == n) return;
    int t = 2 + (s[k] - '0');
    if (t == p) {
        build_tower(k + 1, p);
    } else {
        int dest = 6 - p - t;
        hanoi_tower(n - k - 1, p, dest);
        ans.push_back({p, t});
        build_tower(k + 1, dest);
    }
}

void solve() {
    cin >> n >> s;
    build_tower(0, 1);
    for (auto [u, v] : ans) {
        cout << u << " " << v << endl;
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
