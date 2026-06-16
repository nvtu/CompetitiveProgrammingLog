#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n;

void solve() {
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    stack<pair<int, int>> stk;
    stk.push({p[1], p[1]});
    for (int i = 2; i <= n; i++) {
        pair<int, int> cur = stk.top();
        stk.pop();
        if (p[i] + 1 == cur.first || p[i] - 1 == cur.second) {
            if (p[i] + 1 == cur.first) cur.first = p[i];
            if (p[i] - 1 == cur.second) cur.second = p[i];
            while (!stk.empty()) {
                pair<int, int> prev = stk.top();
                if (prev.second + 1 == cur.first) {
                    cur.first = prev.first;
                    stk.pop();
                } else if (prev.first - 1 == cur.second) {
                    cur.second = prev.second;
                    stk.pop();
                } else
                    break;
            }
            stk.push(cur);
        } else {
            stk.push(cur);
            stk.push({p[i], p[i]});
        }
    }
    if (stk.size() == 1) {
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
