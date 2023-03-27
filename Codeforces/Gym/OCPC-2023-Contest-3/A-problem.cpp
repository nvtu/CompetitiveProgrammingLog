#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);


void solve() {
    long long n, m, sum = 0, a, min, total, answer_s, answer_d;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        sum += a;
    }
    min = m;
    for (long long s = 0; s < 10000; ++s) {
        for (long long d = 0; d < 10000; ++d) {
            total = (n * s + n*(n+1)/2 * d + sum) % m;
            if (total < min) {
                min = total;
                answer_s = s;
                answer_d = d;
                if (min == 0) {
                    break;
                }
            }
            // cout << s << " " << d << " " << total << endl;
        }
    }
    cout << min << endl;
    cout << answer_s << " " << answer_d << endl;
}


int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
