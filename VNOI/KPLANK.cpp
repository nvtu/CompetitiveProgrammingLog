#include <bits/stdc++.h>
using namespace std;
const int SZ = int(1e6+5);

int N, A[SZ], l[SZ], r[SZ];

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
    int mmax = 0;
    for (int i=0; i<N; i++) {
        if (r[i] - l[i] >= A[i]) mmax = max(mmax, A[i]);
    }
    cout << mmax << endl;
}

int main() {
//    freopen("input.txt", "r", stdin); 
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i=0; i<N; i++) cin >> A[i];
    solve();
    return 0;
}

