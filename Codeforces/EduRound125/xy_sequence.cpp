#include <iostream>
using namespace std;

int t, n, B, x, y;

long long solve() {
    long long maxSum = 0;
    int cur = 0;
    for (int i=0; i<n; i++) {
        if (cur+x <= B) cur += x;
        else cur -= y;
        maxSum += 1LL * cur;
    }
    return maxSum;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n >> B >> x >> y;
        long long sum = solve();
        cout << sum << endl;
    }
    return 0;
}
