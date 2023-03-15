#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

int T, N;

void solve() {
    cin >> T;
    while (T--) {
        cin >> N;
        if (N == 2) {
            cout << -1 << endl;
            continue;
        }
        for (int i=0; i<N; i++) {
            string s = "";
            for (int j=0; j<i+1; j++) s += "1";
            for (int j=i+1; j<N; j++) s += "0";
            if (i == 1) s[0] = '0';
            cout << s << endl;
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
