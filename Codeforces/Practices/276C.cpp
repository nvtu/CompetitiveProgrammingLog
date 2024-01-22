#include <iostream>
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

const int MAX_SIZE = int(2e5+5);
const long long MOD = int(1e9+7);
const double EPS = 1e-6;

int n, q, l[MAX_SIZE], r[MAX_SIZE];
long long a[MAX_SIZE], ans[MAX_SIZE];
pair<long long, long long> b[MAX_SIZE];

bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
    return a.second > b.second;
}

void solve() {
    cin >> n >> q;
    for (int i=1; i<n+1; i++) cin >> a[i];
    for (int i=0; i<q; i++) {
        cin >> l[i] >> r[i];
        b[l[i]].second += 1;
        b[r[i]+1].second -= 1;
    }
    for (int i=1; i<n+1; i++) {
        b[i].first = i;
        b[i].second += b[i-1].second;
    }
    sort(a+1, a+n+1, greater<long long>());
    sort(b+1, b+n+1, cmp);
    for (int i=1; i<n+1; i++) ans[b[i].first] = a[i];

    // Compute range sum queries
    for (int i=1; i<n+1; i++) ans[i] += ans[i-1];
    long long total = 0;
    for (int i=0; i<q; i++) total += ans[r[i]] - ans[l[i]-1];
    cout << total << endl;
}


int main() {
    // freopen("inp.txt", "r", stdin);
    
    //Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();     
    return 0;
}

