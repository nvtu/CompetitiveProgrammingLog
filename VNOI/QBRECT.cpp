#include <bits/stdc++.h>
using namespace std;
const int SZ = 1003;

int M, N, f[SZ], k;


int solve() {
    int l[SZ], r[SZ], ans = 0;
    deque<int> q;
    for (int i=0; i<N; i++) {
        l[i] = -1;
        while (q.size() && f[q.back()] >= f[i]) q.pop_back();
        if (q.size()) l[i] = q.back();
        q.push_back(i);
    }
    q.clear();
    for (int i=N-1; i>=0; i--) {
        r[i] = N;
        while (q.size() && f[q.back()] >= f[i]) q.pop_back();
        if (q.size()) r[i] = q.back();
        q.push_back(i);
    }
    for (int i=0; i<N; i++) {
        ans = max(ans, f[i]*(r[i]-l[i]-1));
    }
    return ans;  
}

int main() {
//    freopen("input.txt", "r", stdin); 
    ios::sync_with_stdio(false);
    cin >> M >> N;
    int ans = 0;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            cin >> k;
            f[j] = (!k ? 0 : f[j] + 1);
        }
        ans = max(ans, solve());
    }
    cout << ans << endl;
    return 0;
}

