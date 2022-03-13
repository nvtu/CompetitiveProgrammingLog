#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int SZ = int(1e5+5);

int N, X, K, b;
pair<int, int> a[SZ];
pair<int, long long> t[SZ];
long long ans = 0;
set<int> posSet;

long long process(int pos) {
    set<int>::iterator itLow = posSet.lower_bound(pos);
    set<int>::iterator itUp = posSet.upper_bound(pos);
    int l = *(--itLow)+1, r = *itUp-1;
    long long cnt = 1LL * (r-pos+1) * (pos-l+1);
    posSet.insert(pos);
    return cnt;
}

bool cmp(pair<int, long long> A, pair<int, long long> B) {
    return A.second < B.second;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> N >> X >> K;
    for (int i=0; i<N; i++) {
        cin >> b;
        a[i] = {b, i+1};
    }
    sort(a, a+N);
    posSet.insert(N+1);
    posSet.insert(0);
    for (int i=N-1; i>=0; i--) {
        int pos = a[i].second;
        t[i] = {a[i].first, process(pos)};
    }
    posSet.clear();
    posSet.insert(N+1);
    posSet.insert(0);
    for (int i=0; i<N; i++) {
        int pos = a[i].second;
        t[i].second -= process(pos);
    }
    sort(t, t+N, cmp);
    for (int i=N-1; i>=0; i--) {
        if (X > 0 && t[i].second > 0) {
            t[i].first++;
            X--;
        }
        ans += 1LL * t[i].first * t[i].second; 
    }
    cout << ans << endl;
    return 0;
}

