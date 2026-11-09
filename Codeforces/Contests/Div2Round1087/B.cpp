#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(5e3 + 5);
const long long MOD = int(1e9 + 7);
int t, n, a[MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) {
            int cnt = 0, cntr = 0;
            for (int j = i + 1; j < n; j++) {
                if (a[j] > a[i])
                    cnt++;
                else if (a[j] < a[i])
                    cntr++;
            }
            cout << max(cnt, cntr) << " ";
        }
        cout << endl;
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
