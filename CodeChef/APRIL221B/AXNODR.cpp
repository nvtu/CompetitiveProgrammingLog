#include <bits/stdc++.h>
using namespace std;

int T;
long long N;

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        long long ans = 1;
        cin >> N;
        if (N > 1) {
            int rem = N % 4;
            if (rem > 1) ans = 3;
            else if (rem == 0) ans = N + 3;
            else if (rem == 1) ans = N;
        }
		cout << ans << endl;
    }
    return 0;
}

