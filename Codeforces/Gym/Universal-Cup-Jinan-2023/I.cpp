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

const int MAX_SIZE = int(1e2+5);
const long long MOD = int(1e9+7);
const double EPS = 1e-6;

int T, n, a[MAX_SIZE];

void solve() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i=0; i<n; i++) cin >> a[i];
        vector<int> sortedA(a, a+n);
        sort(sortedA.begin(), sortedA.end());
        vector<pair<int, int> > ans;
        for (int i=0; i<n; i++) {
            if (sortedA[i] == a[i]) continue;
            for (int k=n-1; k>i; k--) {
                if (a[k] < a[i]) {
                    ans.push_back(make_pair(i+1, k+1));
                    sort(a+i, a+k+1);
                    break; 
                }
            }
        }
        cout << ans.size() << endl;
        for (int i=0; i<ans.size(); i++) {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
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