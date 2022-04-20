#include <bits/stdc++.h>
using namespace std;
const int SZ = int(1e4+5);

int T, N, A[SZ];
vector<int> v[2];


int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        for (int i=0; i<2; i++) v[i].clear();
        cin >> N;
        for (int i=0; i<N; i++) {
            cin >> A[i];
            int rem = A[i] % 2;
            v[rem].push_back(i+1);
        }
        int rem = A[0] % 2, ans = INT_MAX, last = A[N-1] % 2;
        if (last == rem) ans = int(v[rem].size()) - 1;
        else {
            ans = int(v[1-rem].size());
            for (int i=1; i<(int) v[1-rem].size(); i++) {
                int pos = v[1-rem][i-1] + 1;
                if (pos == v[1-rem][i]) continue;
                else {
                    pos = lower_bound(v[rem].begin(), v[rem].end(), pos) - v[rem].begin();
                    ans = min(ans, int(v[1-rem].size()) - i + pos);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

