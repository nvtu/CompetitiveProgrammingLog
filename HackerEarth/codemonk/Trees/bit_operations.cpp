#include <iostream>
#include <numeric>
using namespace std;
const int MAX_SIZE = int(2e5+5);

int n, q, l, r, o, X, arr[MAX_SIZE];

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> q;
    while (q--) {
        cin >> o >> l >> r;
        l--;
        if (o < 4) {
            cin >> X;
            for (int i=l; i<r; i++) {
                if (o == 1) arr[i] |= X;
                else if (o == 2) arr[i] &= X;
                else if (o == 3) arr[i] ^= X;
            }
        }
        else if (o == 4) cout << accumulate(arr+l, arr+r, 0LL) << endl;
        else if (o == 5) cout << accumulate(arr+l, arr+r, 0LL, [](int a, int b) { return a ^ b; }) << endl;
    }
    return 0;
}

