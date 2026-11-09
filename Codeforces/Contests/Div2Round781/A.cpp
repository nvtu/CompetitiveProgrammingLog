#include <iostream>
using namespace std;

int t, n;

int main() {
//    freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n;
        n -= 3;
        cout << 1 << " " << n << " " << 1 << " " << 1 << endl;
    }
    return 0;
}

