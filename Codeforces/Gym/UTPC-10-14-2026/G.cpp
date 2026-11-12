#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n, deg[26], p[26], used[26];
string f[MAX_SIZE];

bool check() {
    int plus = 0, minus = 0;
    for (int i = 0; i < 26; i++) {
        if (deg[i] == 0) continue;
        if (deg[i] == 1)
            plus++;
        else if (deg[i] == -1)
            minus++;
        else
            return false;
    }
    return (plus == 0 && minus == 0) || (plus == 1 && minus == 1);
}

int find_parent(int u) {
    return (u == p[u] ? u : p[u] = find_parent(p[u]));
}

void solve() {
    cin >> n;
    for (int i = 0; i < 26; i++) p[i] = i;
    memset(deg, 0, sizeof(deg));
    memset(used, false, sizeof(used));
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        int a = f[i][0] - 'a';
        int b = f[i].back() - 'a';
        deg[a]--;
        deg[b]++;
        used[a] = used[b] = true;
        p[find_parent(b)] = find_parent(a);
    }

    int root = -1;
    for (int i = 0; i < 26; i++) {
        if (!used[i]) continue;
        if (root == -1)
            root = find_parent(i);
        else if (find_parent(i) != root) {
            cout << "NO" << endl;
            return;
        }
    }

    if (check()) {
        cout << "YES " << -1 << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (f[i][0] == f[i].back()) continue;
        int a = f[i][0] - 'a', b = f[i].back() - 'a';
        deg[a] += 2;
        deg[b] -= 2;
        if (check()) {
            cout << "YES " << i + 1 << endl;
            return;
        }
        deg[a] -= 2;
        deg[b] += 2;
    }

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
