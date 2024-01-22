#include <iostream>
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
long long n, a, b;


void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        string ans = "No";
        if ((n-1) % b == 0) ans = "Yes"; 
        if (a > 1) {
            long long temp = a;
            while (temp <= n) {
                if ((n-temp) % b == 0) {
                    ans = "Yes";
                    break;
                }
                temp *= a;
            }
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

