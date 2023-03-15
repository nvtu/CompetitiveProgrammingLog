#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e3+5);
const long long MOD = int(1e9+7);

int n;
string s[MAX_SIZE];

void solve() {
    cin >> n;
    int maxLen = 0;
    for (int i=0; i<n; i++) {
        cin >> s[i];
        maxLen = max(maxLen, (int) s[i].length());
    }

    string ans = "";

    for (int i=0; i<maxLen; i++) {
        float sum = 0;
        int cnt = 0;
        for (int j=0; j<n; j++) {
            int len = s[j].length();
            if (i < len) {
                sum += (int) s[j][i];
                cnt++;
            }
        }
        int c = sum / cnt;
        ans += (char) (c);
    }
    cout << ans << endl;
}


int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
