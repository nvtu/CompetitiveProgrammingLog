#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);
long long psum[MAX_SIZE], ans = LONG_LONG_MAX;
int N, K, B;

void solve() {
    cin >> N >> K >> B;
    for (int i = 0; i < B; i++) {
        int w;
        cin >> w;
        psum[w] = 1;
    }
    for (int i = 1; i <= N; i++)
        psum[i] += psum[i - 1];
    for (int i = K; i <= N; i++) {
        ans = min(ans, psum[i] - psum[i - K]);
    }
    cout << ans << endl;
}

int main() {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
