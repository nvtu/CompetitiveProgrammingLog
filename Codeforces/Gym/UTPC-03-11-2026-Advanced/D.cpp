#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n, ans, cnt[27];
string s;
map<string, bool> exists;

void count(int len, int cur, string t) {
    if (cur == len) {
        if (!exists[t]) ans += t.length();
        exists[t] = true;
        return;
    }
    for (int i = 0; i < 26; i++) {
        char c = i + 'a';
        if (cnt[i] > 0) {
            cnt[i]--;
            count(len, cur + 1, t + c);
            cnt[i]++;
        }
    }
}

void solve() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }
    for (int i = 1; i < n + 1; i++) count(i, 0, "");
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
