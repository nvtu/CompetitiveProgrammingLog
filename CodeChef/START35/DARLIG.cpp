#include <bits/stdc++.h>
using namespace std;

int T, N, K;

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        N %= 4;
        if (K) {
            if (N == 0) cout << "On" << endl;
            else cout << "Ambiguous" << endl; 
        }
        else {
            if (N) cout << "On" << endl;
            else cout << "Off" << endl;
        }
    }
    return 0;
}

