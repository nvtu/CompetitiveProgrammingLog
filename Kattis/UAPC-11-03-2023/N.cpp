#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

long long T, S[2];
long long N[2];


void solve() {
    cin >> T;
    cin >> N[0] >> N[1];
    cin >> S[0] >> S[1];

    if (S[1] < S[0]) {
        swap(S[0], S[1]);
        swap(N[0], N[1]);
    }

    long long ans = 0;
    long long y = T / S[1];
    long long x = (T - y * S[1]) / S[0];

    while (N[0] > 0 && N[1] > 0) {
        ans++;
        N[0] -= x;
        N[1] -= y;
    }

    for (int i=0; i<2; i++) {
        if (N[i] > 0) {
            x = T / S[i];
            while (N[i] > 0) {
                ans++;
                N[i] -= x;
            }
        }
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
