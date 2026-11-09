#include <bits/stdc++.h>
using namespace std;

int T, N, R, B;

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N >> R >> B;
        int div = R / (B+1), rem = R % (B+1);
        string ans = ""; 
        for (int i=0; i<div; i++) ans += "R";
        for (int i=0; i<B; i++) {
            ans += "B";
            for (int j=0; j<div; j++) ans += "R";
            if (rem > 0) ans += "R", rem--;
        }
        cout << ans << endl;
    }
    return 0;
}

