#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t;
pair<int, string> c[3];
string ans = "";

string select_next(bool follow_rule = false) {
    sort(c, c + 3);
    int len = ans.length();
    for (int i = 2; i >= 0; i--) {
        if (c[i].first == 0) continue;
        if (follow_rule) {
            if (ans[len - 1] == c[i].second[0]) {
                continue;
            }
            if (len > 2 && ans[len - 3] == c[i].second[0]) {
                continue;
            }
        }
        c[i].first--;
        return c[i].second;
    }
    return "";
}

void solve() {
    cin >> t;
    while (t--) {
        for (int i = 0; i < 3; i++) {
            cin >> c[i].first;
        }
        c[0].second = "R";
        c[1].second = "G";
        c[2].second = "B";
        ans = "";
        while (true) {
            string t = select_next(true);
            if (t == "") break;
            ans += t;
        }
        // ans += select_next();
        cout << ans << endl;
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
