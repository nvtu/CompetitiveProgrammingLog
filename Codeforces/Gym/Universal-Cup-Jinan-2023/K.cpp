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
const double EPS = 1e-9;

int T, n;
long long k;

bool check(set<long long> &s) {
    if (s.empty()) return false;
    int cnt = 0;
    int sz = s.size();
    int medianIndex = (sz-1)/2;
    long long need = 0;
    for (set<long long>::iterator it = s.begin(); it != s.end(); it++) {
        if (cnt == medianIndex) {
            if (sz & 1) {
                cnt++;
                continue;
            }
            else need -= *it;
        }
        else if (cnt > medianIndex) need += *it;
        else need -= *it;
        cnt++;
    }
    return need <= k;
}

void solve() {
    cin >> T;
    while (T--) {
        cin >> n >> k;
        vector<long long> a(n+1);
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            a[i] -= i;
        }
        int i = 0, j = 0, ans = 0;
        set<long long> s;
        while (j < n && i <= j) {
            s.insert(a[j++]);
            while (!check(s)) {
                s.erase(a[i++]);
            }
            ans = max(ans, j-i);
        }
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