#include <iostream>
#include <algorithm>
using namespace std;
const int SZ = int(1e5+5);


int t, n;
pair<int, int> a[SZ];


int main() {
    freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> a[i].first;
            a[i].second = i+1;
        }
        sort(a, a+n);
        cout << a[0].second << " " << a[n-1].second << endl;
    }
    return 0;
}

