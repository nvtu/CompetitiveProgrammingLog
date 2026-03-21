#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int N, A[MAX_SIZE], p[MAX_SIZE], s[MAX_SIZE];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    int ans = 0;
    for (int i = 1; i <= N; i++) p[i] = __gcd(p[i - 1], A[i]);
    for (int i = N; i >= 1; i--) s[i] = __gcd(s[i + 1], A[i]);
    for (int i = 1; i <= N; i++) {
        ans = max(ans, __gcd(p[i - 1], s[i + 1]));
    }
    cout << ans << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
