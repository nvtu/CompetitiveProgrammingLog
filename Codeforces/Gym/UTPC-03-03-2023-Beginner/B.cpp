#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

int n;
// create an array of 10 elements and init with 0
int a[10];

int form_num(bool accending = true) {
    int ans = 0;
    if (accending) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < a[i]; j++) {
                ans = ans*10 + i;
            }
        }
    }
    else {
        for (int i = 9; i >= 0; i--) {
            for (int j = 0; j < a[i]; j++) {
                ans = ans*10 + i;
            }
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    while (n != 0) {
        a[n%10]++;
        n/=10;
    }
    int l = form_num();
    int r = form_num(false);
    cout << r-l << endl;
}


int main() {
    // freopen("input.txt", "r", stdin);
    
    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
