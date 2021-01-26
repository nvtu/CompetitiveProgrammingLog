#include <bits/stdc++.h>
using namespace std;

const int MAX_ITEMS = int(2e5+5);
int t, n, m;
pair<int, int> app[MAX_ITEMS];


int main() {
    freopen("D.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cout << endl;
        cin >> n >> m;
        for (int i=0; i<n; i++) cin >> app[i].second;
        for (int i=0; i<n; i++) cin >> app[i].first;
        sort(app, app+n);
        long long ans = int(1e9), convScore = 0, memScore = 0;
        int fPtr = 0, sPtr = 0;
        while (fPtr <= sPtr) {
            while (fPtr < sPtr) {
                memScore -= 1LL * app[fPtr].second;
                convScore -= 1LL * app[fPtr].first;
                fPtr++;
                if (memScore >= m) ans = min(ans, convScore);
                else break;
            }
            while (sPtr < n && memScore < m) {
                memScore += 1LL * app[sPtr].second; 
                convScore += 1LL * app[sPtr].first;
                sPtr++;
            }
            cout << memScore << endl;
            if (memScore >= m) ans = min(ans, convScore);
        }
        if (ans == int(1e9)) ans = -1;
        cout << ans << endl;
    }
    return 0;
}
