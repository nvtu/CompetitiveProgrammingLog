#include <bits/stdc++.h>
using namespace std;

long long A, B, K;

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> A >> B >> K;
    int ans = 0;
    while (A < B) {
        ans++;
        A *= K;
    }
    cout << ans << endl;
    return 0;
}

