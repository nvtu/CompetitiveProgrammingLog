#include<bits/stdc++.h>

using namespace std;

int ask(int a, int b) {
    cout << '?' << " " << a << " " << a + b << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solve() {
    int r = 0;
    for (int i = 1; i <= 30; i++) {
        int ans = ask((1 << (i - 1)) - r, (1 << i));
        if (ans == (1 << i)) r += (1 << (i - 1));
    }
    cout << '!' << " " << r << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
