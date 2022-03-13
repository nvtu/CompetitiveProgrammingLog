#include <bits/stdc++.h>
using namespace std;

const int MMAX = int(5e5+5);
int T, N, h[MMAX], rh[MMAX];


int maxDistanceStarLooking(int N, int hei[]) {
    int ans = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (hei[j] > hei[i]) {
                ans = max(ans, j - i);
                break;
            }
        } 
    }
    return ans;
}


int main() {
    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i=0; i<N; i++) cin >> h[i];
        for (int i=0; i<N; i++) rh[i] = h[N-i-1];
        h[N] = rh[N] = 0;
        int ans = max(maxDistanceStarLooking(N, h), maxDistanceStarLooking(N, rh));
        cout << ans << endl;
    }
    return 0;
}