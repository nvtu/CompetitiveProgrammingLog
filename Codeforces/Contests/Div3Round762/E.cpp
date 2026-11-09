#include <bits/stdc++.h>
using namespace std;
const int SZ = int(2e5+5);

int t, n;
long long a;
map<long long, long long> cnt;

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cnt.clear();
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> a;
            cnt[a]++;
        }
        vector<long long> r;
        long long operation = 0, i = 0;
        while (i <= n) {
            cout << cnt[i] + operation << " ";
            for (int j=0; j<cnt[i]-1; j++) r.push_back(i);
            if (cnt[i] == 0) {
                if (!r.empty()) {
                    operation += i - r.back();
                    r.pop_back();
                }
                else {
                    i++;
                    break;
                }
            }
            i++;
        }
        for (; i <= n; i++) cout << -1 << " ";
        cout << endl;
    }
    return 0;
}

