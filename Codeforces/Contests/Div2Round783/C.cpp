#include <bits/stdc++.h>
using namespace std;
const int SZ = 5005;

long long n, a[SZ];

long long trySolve(int pos) {
    long long cur = -1;
    long long res = 0;
    for (int i=pos-1; i>=0; i--) {
        long long div = (cur + 1 - a[i]) / a[i];
        long long b = div * a[i];
        res += abs(div); 
        cur = b-1;
    }
    cur = 1;
    for (int i=pos+1; i<n; i++) {
        long long div = (cur + a[i] - 1) / a[i];
        long long b = div * a[i];
        res += abs(div);
        cur = b+1;
    }
    return res;
}

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    long long ans = LLONG_MAX;
    for (int i=0; i<n; i++) {
        ans = min(ans, trySolve(i)); // Suppose that position i is 0
    }
    cout << ans << endl;
    return 0;
}

