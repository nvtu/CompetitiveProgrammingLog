#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e6+5);
const long long MOD = int(1e9+7);

int n, m;
long long a;

vector<int> findRelativePrimes(int m) {
    vector<int> ans;
    for (int i=1; i<m; i++) {
        if (__gcd(i, m) == 1) {
            ans.push_back(i);
        }
    }
    return ans;
}

void solve() {
    cin >> n >> m;
    vector<int> f = findRelativePrimes(m);
    int len = f.size();
    for (int i = 0; i < n; i++) {
        cin >> a;
        a--;
        long long q = a / len;
        long long r = a % len;
        long long ans = q * m + f[r];
        cout << ans << " ";
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
