#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

int pos (char x) {
    return x - 'A';
}

void solve() {
    string s, t;
    cin >> s;
    cin >> t;
    int letter_s[26] = {0};
    int letter_t[26] = {0};
    for (int i = 0; i < s.length(); i++) {
        letter_s[s[i]-'A']++;
    }
    for (int i = 0; i < t.length(); i++) {
        letter_t[t[i]-'A']++;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        if (i != 'B'-'A' && i != 'X'- 'A') {
            if (letter_t[i] > letter_s[i]) {
                ans += letter_t[i] - letter_s[i];
                letter_t[i] -= letter_s[i];
                letter_s[i] = 0;
            }
        }
    }

    string smake = "IP";
    string starget = "XB";
    for (int i = 0; i < smake.length(); i++) {
        if (letter_t[pos(starget[i])] > letter_s[pos(starget[i])]) {
            int need = (letter_t[pos(starget[i])] - letter_s[pos(starget[i])]) * 2;
            ans += need - max(letter_t[pos(smake[i])] - letter_s[pos(smake[i])], 0);
        }
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
