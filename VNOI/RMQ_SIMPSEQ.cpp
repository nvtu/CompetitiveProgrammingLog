#include <bits/stdc++.h>
using namespace std;
const int SZ = int(3e5+5);
const int ISZ = int(log2(SZ));

long long n, a[SZ], m[SZ][ISZ];

long long gcd(long long x, long long y) {
    return !y ? x : gcd(y, x % y);
}


void buildRMQ() {
    for (long long i=0; i<n; i++) m[i][0] = a[i];
    for (long long j=1; (1<<j)<=n; j++) {
        for (long long i=0; i+(1<<j)-1<n; i++) {
            m[i][j] = gcd(m[i][j-1], m[i+(1<<(j-1))][j-1]);             
        }
    }
}


long long queryRMQ(long long l, long long r) {
    long long k = int(log2(r-l+1));
    return gcd(m[l][k], m[r-(1<<k)+1][k]);
}


long long findBoundary(long long pos, long long l, long long r) {
    bool leftBound = false;
    if (pos == r) leftBound = true;
    while (l<=r) {
        long long mid = (l+r)>>1;
        long long v = (!leftBound ? queryRMQ(pos, mid) : queryRMQ(mid, pos));
        if (a[pos] == v) {
            if (leftBound) r = mid-1;
            else l = mid+1;
        }
        else {
            if (leftBound) l = mid+1;
            else r = mid-1;
        }
    }
    return (leftBound ? r+1 : l-1); 
}


void solve() {
    buildRMQ(); 
    long long ans = 0;
    for (long long i=0; i<n; i++) {
        long long r = findBoundary(i, i, n-1);
        long long l = findBoundary(i, 0, i);
        ans += 1LL * (i-l) * (r-i+1) + 1LL * (r-i) * (i-l+1);
    }
    cout << ans << endl;
}

int main() {
    freopen("input.txt", "r", stdin); 
    ios::sync_with_stdio(false);

    cin >> n;
    for (long long i=0; i<n; i++) cin >> a[i];
    solve();

    return 0;
}

