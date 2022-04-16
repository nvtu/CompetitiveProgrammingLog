#include <bits/stdc++.h>
using namespace std;

int T, N;

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        if (N & 1) cout << -1 << endl;
        else {
            int A = 0, B = 0, C = 0;
            for (int i=0; i<32; i++) {
                if (N & (1 << i)) {
                    if (B == 0) B |= (1 << (i-1));
                    else A |= (1 << (i-1));
                }
            }
            if (A == C) cout << -1 << endl;
            else cout << A << " " << B << " " << C << endl;
        }
    }
    return 0;
}

