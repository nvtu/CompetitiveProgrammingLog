#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

int T, N, A[MAX_SIZE], cnt[2];

void solve() {
    cin >> T;
    while (T--) {
        cin >> N;
        memset(cnt, 0, sizeof(cnt));
        int ans = 0;
        for (int i=0; i<N; i++) {
            cin >> A[i];
            cnt[A[i]]++;
        }
        if ((N & 1) || cnt[1] == 0) ans = -1;
        else {
            while (cnt[0] < cnt[1] && cnt[1] > 0) {
                ans++;
                cnt[0] += 2;
                cnt[1] -= 2;
            }
            while (cnt[0] > cnt[1] && cnt[0] > 0 && cnt[1] > 0) {
                ans++;
                cnt[0]--, cnt[1]++;
            }
            if (cnt[0] != cnt[1]) ans = -1;
        }
        cout << ans << endl;
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
