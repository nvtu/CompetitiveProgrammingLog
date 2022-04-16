#include <bits/stdc++.h>
using namespace std;
const int SZ = int(2e5+5);

int N, A, Q, L, R, X;
vector<int> m[SZ];

int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> A;
        m[A].push_back(i+1); 
    }
    cin >> Q;
    for (int i=0; i<Q; i++) {
        cin >> L >> R >> X;
        int ans = lower_bound(m[X].begin(), m[X].end(), R+1) - lower_bound(m[X].begin(), m[X].end(), L);
        cout << ans << endl;
    }
    return 0;
}

