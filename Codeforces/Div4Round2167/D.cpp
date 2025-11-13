#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);
int t, n;
long long a[MAX_SIZE];
vector<int> prime;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void solve() {
    for (int i = 2; i < 60; i++) {
        if (is_prime(i)) prime.push_back(i);
    }
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int j = 0; j < prime.size(); j++) {
            bool ok = false;
            for (int i = 0; i < n; i++) {
                if (a[i] % prime[j]) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                cout << prime[j] << endl;
                break;
            }
        }
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
