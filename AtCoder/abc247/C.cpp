#include <bits/stdc++.h>
using namespace std;

int N;

void solve(int state = 1, string s = "") {
    if (state < N) {
        s = s + to_string(state) + " " + s;
        solve(state+1, s);
    }
    else {
        cout << s << state << " " << s << endl;
    }
}

int main() {
   // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    solve();
    return 0;
}

