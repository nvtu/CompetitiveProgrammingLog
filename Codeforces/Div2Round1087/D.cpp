#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t;
pair<int, string> c[3];
string ans = "";

string select_next() {
    int mmax = 0;
    int len = ans.length();
    int p = -1;
    for (int i = 2; i >= 0; i--) {
        if (c[i].first == 0) continue;
        if (ans[len - 1] == c[i].second[0]) {
            continue;
        }
        if (len > 2 && ans[len - 3] == c[i].second[0]) {
            continue;
        }
        if (c[i].first > mmax) {
            mmax = c[i].first;
            p = i;
        } else if (mmax == c[i].first) {
            if (len >= 2 && ans[len - 2] == c[i].second[0]) {
                p = i;
            }
        }
    }
    if (p != -1) {
        c[p].first--;
        return c[p].second;
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
            string next = select_next();
            if (next == "") break;
            ans += next;
        }
        cout << ans << endl;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}