#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(25e4 + 5);
const long long MOD = int(1e9 + 7);

int N, dp[MAX_SIZE];
string S;

void solve() {
    cin >> N >> S;
    for (int i = 0; i < 2; i++) dp[i] = 1;
    for (int i = 2; i < N; i++) {
        string t = S.substr(i - 2, 3);
        dp[i] = dp[i - 1];
        if (t == "ABA" || t == "BAB") {
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
        }
    }
    cout << dp[N - 1] << endl;
}

int main() {
    freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
