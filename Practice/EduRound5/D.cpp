#include <bits/stdc++.h>
using namespace std;

const int MMAX = int(5e5+5);
int n,k,a[MMAX], ansL = 0, ansR = 0;
set<int> s;
map<int, int> cnt;

int main() {
    // freopen("test.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> a[i];
    int l = 0, r = 0;
    while (r < n) {
        if (s.size() <= k) s.insert(a[r]), cnt[a[r++]]++;
        if (s.size() <= k) { if (r - l - 1 > ansR - ansL) ansL = l, ansR = r - 1; }
        else {
            cnt[a[l]]--;
            if (cnt[a[l]] == 0) s.erase(a[l]);
            l++;
        }
    }
    cout << ansL + 1 << " " << ansR + 1 << endl;;
    return 0;
}