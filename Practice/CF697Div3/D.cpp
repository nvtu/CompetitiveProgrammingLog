#include <bits/stdc++.h>
using namespace std;

const int MAX_ITEMS = int(2e5+5);
int t, n, m, memStore[MAX_ITEMS], score;
vector<int> regApp, impApp;


int main() {
    // freopen("D.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i=0; i<n; i++) cin >> memStore[i];
        for (int i=0; i<n; i++) {
            cin >> score;
            if (score == 1) regApp.push_back(memStore[i]);
            else if (score == 2) impApp.push_back(memStore[i]);
        }
        sort(regApp.rbegin(), regApp.rend());
        sort(impApp.rbegin(), impApp.rend());
        long long sumRegApp = 0, sumImpApp = accumulate(impApp.begin(), impApp.end(), 0LL);
        int ans = INT_MAX, r = (int) impApp.size();
        for (int l=0; l <= (int) regApp.size(); l++) {
            while (r > 0 && sumRegApp + sumImpApp - impApp[r-1] >= m) sumImpApp -= impApp[--r];
            if (sumRegApp + sumImpApp >= m) ans = min(ans, 2 * r + l);
            if (l != (int)regApp.size()) sumRegApp += regApp[l];
        }
        regApp.clear();
        impApp.clear();
        cout << (ans == INT_MAX ? -1 : ans) << endl;
    }
    return 0;
}
