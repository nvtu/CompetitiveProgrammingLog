#include <bits/stdc++.h>
using namespace std;

int T, N, X;

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> X;
        int rem = X % N;
        if (rem) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}

