#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

long long a, b, c;

void solve() {
    cin >> a >> b >> c;
    long long sum = a + b;
    if (sum == c) cout << "correct!" << endl;
    else cout << "wrong!" << endl;
}


int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
