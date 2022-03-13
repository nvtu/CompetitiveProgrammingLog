#include <iostream>
#include <map>
using namespace std;

int T, a, b, d;
map<int, int> mark;
map<tuple<int, int, int>, int> cache;

int GCD (int A, int B) {
    return !B ? A : GCD(B, A%B);
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> T;
    while (T--) {
        mark.clear();
        int ans = 0;
        cin >> a >> b >> d;
        if (b < a) swap(a, b);
        int gcd = GCD(a, b);
        gcd = GCD(gcd, d);
        b /= gcd, a /= gcd, d /= gcd;
        if (cache[{a,b,d}] != 0) {
            ans = max(0, cache[{a,b,d}]);
        }
        else {
            for (int i = 0; i < (d+b)/b; i++) {
                int j = d - i * b;
                int rem = j % a;
                if (!rem) {
                    int temp = (d+b)/b-1;
                    ans = 1;
                    if (temp >= i+a) ans += (temp-(i+a))/a + 1;
                    break;
                }
                if (!mark[rem]) mark[rem] = 1; 
                else break;
           }
           cache[{a,b,d}] = !ans ? -1 : ans;
        }
        cout << ans << endl;
    }
    return 0;
}

