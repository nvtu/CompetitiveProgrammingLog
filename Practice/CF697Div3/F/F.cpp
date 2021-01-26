#include <bits/stdc++.h>
using namespace std;

const int MAX_ITEMS = int(1e3+5);
int t, n;
string a[MAX_ITEMS], b[MAX_ITEMS];



int main() {
    // freopen("F.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i < n; i++) cin >> a[i];
        for (int i=0; i < n; i++) cin >> b[i];
        for (int i=0; i < n; i++) {
            if (a[0][i] != b[0][i]) {
                // Transform column i by xor operator
                for (int j=0; j < n; j++) {
                    if (a[j][i] == '1') a[j][i] = '0';
                    else a[j][i] = '1';
                }
            }
        }
        for (int i=0; i < n; i++) {
            if (a[i][0] != b[i][0]) {
                // Transform row i by xor operator
                for (int j=0; j < n; j++) {
                    if (a[i][j] == '1') a[i][j] = '0';
                    else a[i][j] = '1';
                }
            }
        }
        string ans = "YES";
        for (int i=0; i < n; i++) {
            if (a[i] != b[i]) {
                ans = "NO";
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
