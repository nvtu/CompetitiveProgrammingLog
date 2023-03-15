#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

string s;

void solve() {
    cin >> s;
    int x = atoi(s.substr(0, 2).c_str());
    int y = atoi(s.substr(3, 2).c_str());
    int z = atoi(s.substr(6, 4).c_str());
    if (x > 12) cout << "EU" << endl;
    else {
        if (y > 12) cout << "US" << endl;
        else cout << "either" << endl;
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
