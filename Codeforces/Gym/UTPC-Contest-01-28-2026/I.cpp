#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int n;
long long h[MAX_SIZE];
set<int> segments;
priority_queue<pair<long long, int>> pq;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (j + 1 <= n && h[j + 1] == h[i]) j++;
        segments.insert(i);
        i = j;
    }
    segments.insert(-1);
    segments.insert(n + 1);
    for (auto index : segments) {
        if (index > 0 && index <= n) pq.push({h[index], index});
    }
    long long ans = 0;
    while (!pq.empty()) {
        int j = pq.top().second;
        pq.pop();
        if (!segments.count(j)) continue;
        if (!h[j]) break;
        int l = *prev(segments.lower_bound(j));
        int r = *segments.lower_bound(j + 1);
        int w = r - j;
        if (h[l] > h[r]) {
            ans += sqr(h[l] - h[j]) * w;
            h[j] = h[l];
            segments.erase(j);
        } else {
            ans += sqr(h[r] - h[j]) * w;
            h[j] = h[r];
            segments.erase(r);
        }
        if (h[l] == h[r]) segments.erase(r);
        pq.push({h[*prev(segments.lower_bound(j + 1))], j});
    }
    cout << ans << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
