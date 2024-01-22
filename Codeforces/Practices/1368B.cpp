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

long long k;

void solve() {
    cin >> k;
    string temp = "codeforces";
    string ans = "";
    long long mul = 1;
    int cnt = 0;
    long long x = pow(mul, 10);
    while (x < k) {
        mul++;
        x = pow(mul, 10);
    }
    while (cnt < 10) {
        if (x / mul * (mul-1) >= k) x = x / mul * (mul -1);
        else break;
        cnt++;
    }
    for (int i=0; i<cnt; i++) {
        for (int j=0; j<mul-1; j++) ans += temp[i];
    }
    for (int i=cnt; i<10; i++) {
        for (int j=0; j<mul; j++) ans += temp[i];
    }
    cout << ans << endl;
}


int main() {
    // freopen("inp.txt", "r", stdin);
    
    //Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();     
    return 0;
}

