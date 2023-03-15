#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

int n, q;
long long pSum[MAX_SIZE], a[MAX_SIZE], k;

int binSearch(int l, int r , long long key) {
    int start = l;
    int ans = -1;
    while (l <= r) {
        int mid = (l+r) >> 1;
        long long sum = pSum[mid] - pSum[start-1];
        if (sum == key) return mid;
        else if (sum < key) l = mid+1;
        else r = mid-1;
    }
    return ans;
}


void solve() {
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        pSum[i] = pSum[i-1] + a[i];
    }
    while (q--) {
        cin >> k;
        int len = INT_MAX, l = 1, r = 1;
        for (int i=1; i<=n; i++) {
            int j = binSearch(i, n, k);     
            if (j != -1 && j-i+1 < len) {
                len = j-i+1;
                l = i;
                r = j;
            }
        }
        cout << l-1 << " " << r-1 << endl;
    }
}


int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
