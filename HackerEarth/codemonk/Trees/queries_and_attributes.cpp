#include <iostream>
#include <limits.h>
#include <cmath>
#include <set>
#include <vector>
using namespace std;
/* 
Ideas:

dp[1] = a[1]
dp[2] = a[1] + a[2]
dp[3]:
2 - 2: a[1] + a[2] + a[3]
1 - 2: a[1] + a[3]

dp[4]:
3 - 3: a[1] + a[3] + a[4]
1 - 1: a[1] + a[4]
1 - 2: a[1] + a[2] + a[4]
1 - 3: a[1] + a[4]
2 - 2: a[1] + a[2] + a[4]

1 <= l <= r <= x => dp[n] = a[n] + y;
1 <= x <= r => dp[n] - a[n] = min(dp_l, dp_r) = dp[k1] (l <= k1 <= r) -> dp[k1] - a[k1] = min.. = dp[k2] ... = a[ki] + y

=> dp[n] = a[n] + a[k1] + a[k2] + ... + a[ki] + y (k1 = min(dp_l[n], dp_r[n]), k2 = min(dp_l[k1], dp_r[k1]), ...) 
=> dp[n] - a[n] = min(dp_l[n], dp_r[n]) = a[k1] + a[k2] + ... + a[ki] + y (where a[k1] + a[k2] +... + a[ki] is minimum

*/
const int MAX_SIZE = int(1e5+5);
long long inf = (long long)(1e18);

int n, q, a[MAX_SIZE], l[MAX_SIZE], r[MAX_SIZE], x, y;
long long b[MAX_SIZE]; // b[i] is the minimum suffix sum before adding a[i]
multiset<long long> s;
vector<long long> add[MAX_SIZE], rem[MAX_SIZE];


int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    for (int i=0; i<n; i++) {
        scanf("%d%d", &l[i], &r[i]);
        l[i]--;
        r[i]--;
    }
    for (int i=n-1; i>=0; i--) {
        for (auto x: add[i]) s.insert(x);
        if (i != n-1) b[i] = s.size() ? *s.begin() : inf;
        if (i > 0) {
            // Add to the potential result list as it might plus a[i] anyway if it is in the minimum set
            add[r[i]].push_back(b[i] + a[i]); 
            rem[l[i]].push_back(b[i] + a[i]);
        }
        for (auto x: rem[i]) s.erase(s.find(x));
    }
    for (int i=1; i<n; i++) b[i] = min(b[i], b[i-1]);
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &x, &y);
        printf("%lld\n", b[x-1]+y);
    }
    return 0;
}

