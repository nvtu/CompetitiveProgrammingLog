#include <iostream>
#include <map>
using namespace std;
const int SIZE = int(1e5+5);

int t, n, a;
map<int, int> cnt;

int main() {
//    freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cnt.clear();
        cin >> n;
        int maxCnt = 0, num = 0, ans = 0;
        for (int i=0; i<n; i++) {
            cin >> a;
            cnt[a]++;
            if (cnt[a] > maxCnt) {
                maxCnt = cnt[a];
                num = a;
            }
        }
        while (maxCnt < n) {
            ans += 1 + min(maxCnt, max(0, n-maxCnt));
            maxCnt = (maxCnt << 1);
        }
        cout << ans << endl;
    }
    return 0;
}

