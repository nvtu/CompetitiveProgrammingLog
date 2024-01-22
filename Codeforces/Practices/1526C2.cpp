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

const int MAX_SIZE = int(2e5+5);
const long long MOD = int(1e9+7);
const double EPS = 1e-6;

int n, a[MAX_SIZE];
multiset<int> s;

void solve() {
    cin >> n;
    long long sum = 0;
    int ans = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i] >= 0) {
            sum += a[i];
            ans++;
        }
        else {
            if (sum + a[i] >= 0) {
                sum += a[i];
                ans++;
                s.insert(a[i]);
            }
            else {
                if (!s.empty() && *s.begin() < a[i]) {
                    sum -= *s.begin();
                    s.erase(s.begin());
                    s.insert(a[i]);
                    sum += a[i];
                }
            }
        }
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

