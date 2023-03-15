#include <bits/stdc++.h>
using namespace std;
const int SZ = int(2e4);

int T, N, A[SZ], k, mmin[SZ];

void solve() {
    deque<int> q;
    for (int i=0; i<N; i++) {
        while (q.size() && A[q.back()] >= A[i]) q.pop_back();
        q.push_back(i);
        if (q.front() + k <= i) q.pop_front();
        if (i >= k-1) mmin[i] = A[q.front()];
    }
    for (int i=k-1; i<N; i++) cout << mmin[i] << " ";
    cout << endl;
}

int main() {
//    freopen("input.txt", "r", stdin); 
    cin >> T;
    while (T--) {
        cin >> N >> k;
        for (int i=0; i<N; i++) cin >> A[i];
        solve();
    }
    return 0;
}

