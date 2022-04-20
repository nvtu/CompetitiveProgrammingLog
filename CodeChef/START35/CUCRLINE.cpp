#include <bits/stdc++.h>
using namespace std;

long long X, Y;
map<long long, long long> cnt;

void countPrimeDivisor(long long a) {
    long long st = sqrt(a);
    for (long long i=2; i<=st && a > 1; i++) {
        while (a % i == 0) {
            a /= i;
            cnt[i]++;
        }
    }
    if (a > 1) cnt[a]++;
}

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> X >> Y;
    long long prod = X * Y;
    long long ans = 1;
    countPrimeDivisor(X);
    countPrimeDivisor(Y);
    for (auto x: cnt) ans *= x.second + 1;
    cout << ans << endl;
    return 0;
}

