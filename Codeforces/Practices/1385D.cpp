#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstdlib>
#include <set>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);
const double EPS = 1e-6;

int t, n;
string s;

int transformGoodStrOptimization(int i, int j, char target) {
    if (i == j) {
        if (s[i] != target) return 1;
        return 0;
    }
    int mid = (i+j)/2;
    int cntLeft = 0;
    // Case 1: Left = target and Right = target + 1
    for (int k=i; k<=mid; k++) {
        if (s[k] != target) cntLeft++;
    }
    cntLeft = cntLeft + transformGoodStrOptimization(mid+1, j, target+1);
    // Case 2: Left = target + 1 and Right = target
    int cntRight = 0;
    for (int k=mid+1; k<=j; k++) {
        if (s[k] != target) cntRight++;
    }
    cntRight = cntRight + transformGoodStrOptimization(i, mid, target+1);
    return min(cntLeft, cntRight);
}

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int ans = transformGoodStrOptimization(0, n-1, 'a');
        cout << ans << endl;
    }
}


int main() {
    // freopen("inp.txt", "r", stdin);

    //Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}