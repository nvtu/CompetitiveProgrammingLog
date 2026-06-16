#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n;
pair<int, int> c[MAX_SIZE];
map<pair<int, int>, bool> check;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i].first >> c[i].second;
        check[c[i]] = true;
    }
    bool ok1 = true, ok2 = true;
    for (int i = 0; i < n; i++) {
        int new_x = c[i].second, new_y = -(c[i].first + c[i].second);
        if (!check[{new_x, new_y}]) {
            ok1 = false;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        int new_y = c[i].first, new_x = c[i].first - c[i].second;
        if (!check[{new_x, new_y}]) {
            ok2 = false;
            break;
        }
    }
    if (ok1 || ok2) {
        cout << "YES" << endl;
    } else
        cout << "NO" << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
