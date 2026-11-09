#include <bits/stdc++.h>
using namespace std;
const int SZ = int(2e5+5);

int n, m, l, r, presum[6][SZ];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> s;
    string t = "abc";
    int j = 0;
    do {
        for (int i=0; i<n; i++) {
            char c = t[i % 3];
            presum[j][i+1] = presum[j][i];
            if (c != s[i]) presum[j][i+1]++;
        }
        j++;
    } while (next_permutation(t.begin(), t.end()));
    for (int i=0; i<m; i++) {
        cin >> l >> r;
        int ans = INT_MAX;
        for (int j=0; j<6; j++) {
            ans = min(ans, presum[j][r] - presum[j][l-1]);
        }
        cout << ans << endl;
    }
    return 0;
}

