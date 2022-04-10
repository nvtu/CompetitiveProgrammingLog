#include <bits/stdc++.h>
using namespace std;
const int SIZE = int(2e5+5);

int t, n, p, sz[SIZE];
vector<int> v;

int main() {
//    freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--) {
		memset(sz, 0, sizeof(sz));
        v.clear();
        cin >> n;
        for (int i=2; i<=n; i++) {
            cin >> p;
			sz[--p]++;
        }
        sort(sz, sz+n, greater<int>());
        int cnt = 1;
        for (int i=0; i<n; i++) {
            if (sz[i] > 0) cnt++;
        }
        int ans = cnt;
        for (int i=0; i<n; i++) {
            sz[i] = max(0, sz[i] - cnt);
            cnt = max(0, cnt-1);
            if (sz[i] > 0) v.push_back(sz[i]);
        }
        sort(v.begin(), v.end());
        while (!v.empty()) {
            bool inject = false;
            int i  = int(v.size()) - 1;
            while (i >= 0) {
                if (v[i] > 0) v[i]--;
                if (!inject && v[i] > 0) v[i]--, inject = true;
                i--;
            }
            sort(v.begin(), v.end());
            while (!v.empty() && v.back() == 0) v.pop_back();
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}

