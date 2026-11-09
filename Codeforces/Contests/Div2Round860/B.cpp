#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

int t, m, n[MAX_SIZE];
vector<int> v[MAX_SIZE], ans;
bool p[MAX_SIZE];


void init() { 
    memset(p, false, sizeof(p));
}

void clear() {
    for (int i=0; i<m; i++) {
        v[i].clear();
    }
    ans.clear();
}

void solve() {
    cin >> t;
    while (t--) {
        init();
        cin >> m;
        for (int i=0; i<m; i++) {
            cin >> n[i];
            int val;
            for (int j=0; j<n[i]; j++) {
                cin >> val;
                v[i].push_back(val);
            }
        }

        for (int i=m-1; i>=0; i--) {
            for (auto x: v[i]) {
                if (!p[x]) {
                    ans.push_back(x);
                    p[x] = true;
                    break;
                }
            }
            for (auto x: v[i]) p[x] = true;
        }

        if ((ans.size()) == m) {
            for (int i=0; i<m; i++) cout << ans[m-i-1] << " ";
            cout << endl;
        }
        else cout << -1 << endl;
        clear();
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
