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

const int MAX_SIZE = int(2e5+5);
const long long MOD = int(1e9+7);
const double EPS = 1e-6;

int n, x, a;
map<long long, long long> cnt;

void solve() {
    cin >> n;
    vector<long long> psum(n+1, 0);
    long long ans = 0;
    for (int i=0; i<n; i++) {
        cin >> a;
        psum[i+1] = psum[i] + a;
        ans += cnt[(psum[i+1] % n + n) % n];
        if (psum[i+1] % n == 0) ans++;
        cnt[(psum[i+1] % n + n) % n]++;
    }
    cout << ans << endl;
}


int main() {
    // freopen("inp.txt", "r", stdin);

    //Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}