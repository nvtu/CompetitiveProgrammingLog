#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

int n, m;
vector<pair<int, long long>> g[MAX_SIZE];
vector<pair<int, int>> deg;
int cnt[MAX_SIZE];
int visited[MAX_SIZE];

void input() { 
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        cnt[u]++;
        cnt[v]++;
    }
    for (int i=1; i<n+1; i++) {
        deg.push_back({cnt[i], i});
    }
}

pair<long long, long long> visit(int u, long long min_w, long long sum, bool all_deg_2 = false) {
    visited[u] += 1;
    for (auto p: g[u]) {
        int v = p.first;
        long long w = p.second;
        pair <long long, long long> val = make_pair(1e18, 0);
        if (visited[v] == 0) {
            val = visit(v, min(min_w, w), sum + w);
            min_w = val.first;
            sum = val.second;
        }
        else {
            visited[v]++;
            min_w = min(min_w, w);
            sum += w;
        }
    }
    return make_pair(min_w, sum);
}

void solve() {
    input();
    sort(deg.begin(), deg.end());
    long long ans = 0;
    int flag = 0;
    for (auto p: deg) {
        int u = p.second;
        if (visited[u] != 0) continue;
        pair <long long, long long> res = visit(u, 1e18, 0);
        if (flag == 0 && p.first == 2) {
            ans = res.second / 2;
            break;
        }
        flag = 1;
        if (visited[u] > 2)
            ans += res.second / 2 - res.first;
        else 
            ans += res.second / 2;

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
