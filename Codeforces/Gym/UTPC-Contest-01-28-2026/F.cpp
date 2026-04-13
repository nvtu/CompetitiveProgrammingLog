#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);
const int GCD_SIZE = int(1e3 + 1);

int n, q, h[MAX_SIZE];
vector<int> d[GCD_SIZE];

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        int hgcd = gcd(h[i], i);
        d[1].push_back(i);
        if (hgcd != 1 && hgcd < GCD_SIZE) {
            d[hgcd].push_back(i);
        }
        for (int j = 2; j <= sqrt(hgcd); j++) {
            if (hgcd % j == 0) {
                if (j < GCD_SIZE) {
                    d[j].push_back(i);
                }
                if (hgcd / j != j && hgcd / j < GCD_SIZE) {
                    d[hgcd / j].push_back(i);
                }
            }
        }
    }
    for (int i = 1; i <= GCD_SIZE; i++) {
        if (d[i].size() > 0) {
            sort(d[i].begin(), d[i].end());
        }
    }
    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        auto lb = lower_bound(d[k].begin(), d[k].end(), l);
        auto up = upper_bound(d[k].begin(), d[k].end(), r);
        cout << up - lb << endl;
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
