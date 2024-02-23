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

int N, psum[MAX_SIZE][3];

int getGestureIndex(char c) {
    if (c == 'H') return 0;
    if (c == 'P') return 1;
    if (c == 'S') return 2;
    return -1;
}

void solve() {
    cin >> N;
    char c;
    for (int i=0; i<N; i++) {
        cin >> c;
        int gestureIndex = getGestureIndex(c);
        psum[i+1][gestureIndex]++;
        for (int j=0; j<3; j++) psum[i+1][j] += psum[i][j];
    }
    int ans = 0;
    for (int i=1; i<=N; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                ans = max(ans, psum[i][j] + psum[N][k] - psum[i][k]);
            }
        }
    }
    cout << ans << endl;
}


int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    //Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}