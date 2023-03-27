#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e6+5);
const long long MOD = int(1e9+7);
const double EPS = 1e-6;

int n;
double a[MAX_SIZE];
double b[MAX_SIZE];
double sum = 0;

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    double ans = sum / (n+1);
    cout << fixed << setprecision(6);
    cout << ans * 2 << " ";
    for (int i=1; i<n; i++) {
        cout << ans << " ";
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
