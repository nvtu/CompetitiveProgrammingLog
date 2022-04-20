#include <bits/stdc++.h>
using namespace std;
const int SZ = int(1e5+5);

int T, X, A[SZ];
long long N;
vector<int> v;
map<int, long long> cnt;


int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        v.clear();
        cnt.clear();
        cin >> N;
        for (int i=0; i<N; i++) cin >> A[i];
        cin >> X;
        for (int i=0; i<N; i++) cnt[A[i] & X]++;
        long long ans = N;
        if (X == 0) ans += N * (N - 1) ;
        else {
            for (auto x: cnt) {
                ans += x.second * (x.second - 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}


