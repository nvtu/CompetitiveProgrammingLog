#include <bits/stdc++.h>
using namespace std;

int T, A, B;

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> A >> B;
        if ((A & 1) == 0) {
            if (A + 2 <= B) cout << A << " " << A + 2 << endl;
            else cout << -1 << endl;
        }
        else {
            if (A % 3 == 0) {
                if (A + 3 <= B) cout << A << " " << A + 3 << endl;
                else cout << -1 << endl;
            }
            else {
                A++;
                if (A <= B && A + 2 <= B) cout << A << " " << A + 2 << endl;
                else cout << -1 << endl;
            }
        }
    }
    return 0;
}

