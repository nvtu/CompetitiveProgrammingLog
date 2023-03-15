#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e3+5);
const long long MOD = int(1e9+7);

int n, v[MAX_SIZE];

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> v[i];
    for (int t=0; t<=1000; t++) {
        int newP = (v[0] * t) % n;
        bool found = true;
        for (int i=1; i<n; i++) {
            int newPO = (v[i] * t + i) % n;
            if (newPO != newP) {
                found = false;
                break;
            }
        }
        if (found) {
            cout << t << " " << newP << endl;
            return;
        }
    }
    cout << -1 << endl;
}


int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
