#include <bits/stdc++.h>
using namespace std;

int t;
long long n;

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        map<long long, bool> cubes;
        for (int i=1; i<=sqrt(n); i++) {
            long long cube = i * i * i;
            if (cube > n) break;
            cubes[cube] = true;
        }
        long long ans = cubes.size();
        for (int i=1; i<=sqrt(n); i++) {
           long long sq = i * i;
           if (!cubes[sq]) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}

