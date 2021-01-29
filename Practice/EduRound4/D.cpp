#include <bits/stdc++.h>
using namespace std;

int n, k, l, r;
vector<pair<int, int> > ans, c;

int main () {
    // freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> l >> r;
        c.push_back({ l, -1 });
        c.push_back({ r, 1 });
    } 
    sort(c.begin(), c.end());
    int cnt = 0;
    for (int i=0; i < (int) c.size(); i++) {
        if (cnt == k - 1 && cnt - c[i].second == k) l = c[i].first;
        else if (cnt == k && cnt - c[i].second == k - 1) ans.push_back({ l, c[i].first }); 
        cnt -= c[i].second;
    }
    cout << (int) ans.size() << endl;
    for (int i=0; i < (int) ans.size(); i++) cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}