#include <bits/stdc++.h>
using namespace std;

const int MAX_ITEMS = int(2e5+5);
int t, n;


int main() {
    // freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        string ans = "YES";
        cin >> n;
        map<long long, bool> isExist;
        vector<long long> d(n*2);
        for (auto& i: d) cin >> i;
        sort(d.begin(), d.end());
        for (int i=1, j=0; i<2*n; i+=2, j++) {
            if (d[i] != d[i-1] || d[i] % 2 || d[i-1] % 2) {
                ans = "NO";
                break;
            }
            else d[j] = d[i];
        }
        if (ans == "YES") {
            long long temp = 0;
            for (int i=n; i>0; i--) {
                long long val = (d[i-1] / 2 - temp) / i;
                if (d[i-1] % 2 || (d[i-1] / 2 - temp) % i || 
                    isExist[val] || isExist[-val] || val <= 0) {
                    ans = "NO";
                    break;
                }
                else isExist[val] = isExist[-val] = true;
                temp += val;
            }
        }
        cout << ans << endl;
    }
    return 0;
}