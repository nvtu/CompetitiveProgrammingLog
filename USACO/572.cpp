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

int N, Q, psum[MAX_SIZE][3], l, r, x;

void solve() {
    cin >> N >> Q;
    for (int i=0; i<N; i++) {
        cin >> x;
        psum[i+1][x-1]++;
        for (int j=0; j<3; j++) psum[i+1][j] += psum[i][j];
    }
    for (int i=0; i<Q; i++) {
        cin >> l >> r;
        cout << psum[r][0] - psum[l-1][0] << " " << psum[r][1] - psum[l-1][1] << " " << psum[r][2] - psum[l-1][2] << endl;
    }
}


int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    //Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}