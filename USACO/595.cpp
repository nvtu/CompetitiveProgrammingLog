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

int N;

void solve() {
    cin >> N;
    vector<int> id(N);
    vector<long long> psum(N+1, 0);
    vector<int> maxIndex(7, -1), minIndex(7, N);
    for (int i=0; i<N; i++) cin >> id[i];
    for (int i=1; i<=N; i++) {
        psum[i] = (psum[i-1] + id[i-1]) % 7;
        maxIndex[psum[i]] = max(maxIndex[psum[i]], i);
        minIndex[psum[i]] = min(minIndex[psum[i]], i);
    }
    int ans = 0;
    for (int i=0; i<7; i++) {
        ans = max(ans, maxIndex[i] - minIndex[i]);
    }
    cout << ans << endl;
}


int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    //Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}