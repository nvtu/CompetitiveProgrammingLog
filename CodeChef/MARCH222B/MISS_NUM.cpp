#include <iostream>
using namespace std;

int t;
long long a[4];

int main() {
//    freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--) {
        for (int i=0; i<4; i++) cin >> a[i];
        bool hasAns = false;
        long long x, y;
        for (int i=0; i<4 && !hasAns; i++) {
            for (int j=0; j<4 && !hasAns; j++) {
                if (i == j) continue;
                x = (a[i] + a[j]) / 2;
                y = (a[i] - a[j]) / 2;
                if (x < 1 || y < 1 || x > int(1e4) || y > int(1e4)) continue;
                if (x + y == a[i] && x - y == a[j]) {
                    int k=0, t=0;
                    for (; k<4; k++) if (k != i && k != j) break;
                    for (; t<4; t++) if (t != k && t != j && t != i) break;
                    if ((x * y == a[k] && x / y == a[t]) || (x * y == a[t] && x / y == a[k])) hasAns = true;
                }
            }
        }
        if (hasAns) cout << x << " " << y << endl;
        else cout << -1 << " " << -1 << endl;
    }
    return 0;
}

