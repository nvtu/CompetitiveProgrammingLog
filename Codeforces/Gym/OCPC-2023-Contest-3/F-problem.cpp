#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

int *power_p = new int[10002];
// set<string> string_set;
set<int> hash_set;

int hash_s(string const &s) {
    int hash_value = 0;
    for (int i = 0; i < s.size(); ++i) {
        hash_value += (s[i] - 'a' + 1) * power_p[i];
    }
    return hash_value;
}

void solve() {
    int p = 1;
    for (int i = 0; i < 1e4+2; ++i) {
        power_p[i] = p;
        p *= 31 % MOD;
    }

    int n, m, pos, hash_value;
    bool found = false;
    string s;
    cin >> n;
    for(int group = 1; group <= n; ++group) {
        cin >> m;
        found = false;
        for (int i = 0; i < m; ++i) {
            cin >> s;
            pos = s.find("bie", 0);
            if (pos != string::npos) {
                hash_value = hash_s(s);
                // if (string_set.find(s) == string_set.end()) {
                if (hash_set.find(hash_value) == hash_set.end()) {
                    found = true;
                    cout << s << endl;
                    // string_set.insert(s);
                    hash_set.insert(hash_value);
                }
            }
        }
        if (!found) {
            cout << "Time to play Genshin Impact, Teacher Rice!" << endl;
        }
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
