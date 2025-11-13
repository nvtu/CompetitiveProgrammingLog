#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n, q, t[MAX_SIZE];
map<int, int> m;
pair<int, int> r[MAX_SIZE];
priority_queue<int, vector<int>, greater<int> > pq;

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> r[i].first >> r[i].second;
    for (int i = 0; i < q; i++) {
        cin >> t[i];
        m[t[i]]++;
    }
    sort(r, r + n);
    int l = 0;
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        while (l < n && r[l].first <= it->first) {
            if (r[l].second >= it->first) pq.push(r[l].second);
            l++;
        }
        while (!pq.empty() && pq.top() < it->first) pq.pop();
        m[it->first] = pq.size();
    }
    for (int i = 0; i < q; i++) {
        cout << m[t[i]] << endl;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
