#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n;
vector<long long> ps;
bool is_prime[MAX_SIZE];

void solve() {
    ps.push_back(1);
    memset(is_prime, true, sizeof(is_prime));
    for (long long i = 2; i < MAX_SIZE; i++) {
        if (is_prime[i]) {
            ps.push_back(i);
            for (long long j = sqr(i); j < MAX_SIZE; j += i) {
                is_prime[j] = false;
            }
        }
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cout << 1 << " ";
        for (int i = 1; i < n; i++) {
            cout << ps[i] * ps[i - 1] << " ";
        }
        cout << endl;
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
