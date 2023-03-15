#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

int T, N, A[MAX_SIZE];

void solve() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i=0; i<N; i++) cin >> A[i];
        long long total = accumulate(A, A+N, 0LL);
        if (total & 1) cout << "NO" << endl;
        else {
            long long cur = 0;
            for (int j=0; j<N; j++) {
                cur += A[j];
                if ((cur & 1) == ((total - cur) & 1)) {
                    cout << "YES" << endl;
                    break;
                }
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
