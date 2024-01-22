#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstdlib>
#include <set>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);
const double EPS = 1e-6;

int t;
long long n, s;

int sumDigit(long long x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

void solve() {
    cin >> t;
    while (t--) {
        long long ans = 0;
        cin >> n >> s;
        long long sum = sumDigit(n);
        long long mul = 10;
        int cnt = 0;
        while (sum > s && cnt <= 18) {
            long long tmp = n % mul;
            long long add = mul - tmp;
            ans += add;
            n += add;
            sum = sumDigit(n);
            mul *= 10;
            
        }
        cout << ans << endl;
    }
}


int main() {
    // freopen("inp.txt", "r", stdin);

    //Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}