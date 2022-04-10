#include <bits/stdc++.h>
using namespace std;

int t, n, cnt[2][2];
string s;

int main() {
//    freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--) {
        memset(cnt, 0, sizeof(cnt));
        cin >> n >> s;
        for (int i=n-1; i>=0; i--) {
            int num = s[i] - '0';
            cnt[(n-i) % 2][num]++;
        }
        int ans = 0, i=0;
        for (; i<n; i+=2) {
            if (cnt[1][1] > 0 && cnt[0][0] > 0) {
                ans++;
                cnt[0][0]--;
                cnt[1][1]--;
            }
            else break;
        }
        i++;
        if (cnt[1][1] > 0) cnt[1][1]--;
        else cnt[1][0]--;
        for (; i<n; i+=2) {
            if (cnt[1][0] > 0 && cnt[0][1] > 0) {
                ans++;
                cnt[0][1]--;
                cnt[1][0]--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

