#include <bits/stdc++.h>
using namespace std;

int T, N, K;
string s;

int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N >> K >> s;
        int cnt[N], ans[N];
        bool even = (K % 2 == 0);
        memset(cnt, 0, sizeof(cnt));
        for (int i=0; i<N; i++) ans[i] = s[i] - '0';
        for (int i=0; i<N && K >= 2; i++) {
            if (even && !ans[i]) ans[i] = 1 - ans[i], K-=2, cnt[i]++;
            else if (!even && ans[i]) K-=2, cnt[i]++;
        }
        for (int i=0; i<N; i++) {
            if (cnt[i] > 0) continue;
            if (!even) ans[i] = 1 - ans[i];
        }
        if (K > 0) {
            int pos = -1;
            for (int i=N-1; i>=0; i--) {
                if ((K & 1) && ans[i]) {
                    pos = i;
                    break;
                }
                else if ((K & 1) == 0 && !ans[i]) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1) {
                cnt[N-1] += K;
                ans[N-1] = (K & 1 ? ans[N-1] : 1 - ans[N-1]);
            }
            else cnt[pos] += K;
        }
        for (int i=0; i<N; i++) cout << ans[i];
        cout << endl;
        for (int i=0; i<N; i++) cout << cnt[i] << " ";
        cout << endl;
    }
    return 0;
}

