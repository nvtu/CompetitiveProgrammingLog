#include <iostream>
#include <cmath>
#define sqr(x) (x)*(x)
using namespace std;

int t, x, y;

int solve() {
    if (x == 0 && y == 0) return 0;
    int dist = sqrt(sqr(x) + sqr(y));
    if (sqrt(sqr(x) + sqr(y)) == dist) return 1;
    return 2;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> x >> y;
        int ans = solve();
        cout << ans << endl;
    }
    return 0;
}

