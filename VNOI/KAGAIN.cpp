#include <bits/stdc++.h>
using namespace std;
const int SZ = int(3e4+5);

int T, N, A[SZ], l[SZ], r[SZ];

void solve() {
    // Find and maintain the range of the minimum values of each element in the array
    deque<int> q;
    for (int i=0; i<N; i++) {
        r[i] = N;
        while (q.size() && A[q.back()] > A[i]) {
            r[q.back()] = i;
            q.pop_back();
        }
        q.push_back(i);
    }
    while (q.size()) q.pop_back();
    for (int i=0; i<N; i++) {
        l[i] = i;
        while (q.size() && A[q.back()] >= A[i]) {
            l[i] = l[q.back()];
            q.pop_back();
        }
        q.push_back(i);
    }
    int mmax = 0, L = 0, R = 0;
    for (int i=0; i<N; i++) {
        int val = A[i] * (r[i] - l[i]);
        if (val > mmax) {
            mmax = val;
            L = l[i];
            R = r[i];
        }
    }
    cout << mmax << " " << L+1 << " " << R << endl;
}

int main() {
//    freopen("input.txt", "r", stdin); 
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i=0; i<N; i++) cin >> A[i];
        solve();
    }
    return 0;
}

