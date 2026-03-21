#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n, m, u, v, low[MAX_SIZE], disc[MAX_SIZE];
long long cost[MAX_SIZE];
bool stackMember[MAX_SIZE];
bool isVisited[MAX_SIZE];
vector<int> edges[MAX_SIZE];
long long minCost = 0, ways = 1;
vector<vector<int>> sccs;
vector<int> stk;

void tarjanSCC(int u, vector<int> edges[], vector<vector<int>>& sccs, vector<int>& stk, int low[], int disc[], bool stackMember[], bool isVisited[], int& time) {
    isVisited[u] = true;
    low[u] = disc[u] = ++time;
    stackMember[u] = true;
    stk.push_back(u);
    for (auto v : edges[u]) {
        if (!isVisited[v]) {
            tarjanSCC(v, edges, sccs, stk, low, disc, stackMember, isVisited, time);
            low[u] = min(low[u], low[v]);
        } else if (stackMember[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }
    if (low[u] == disc[u]) {
        vector<int> scc;
        while (stk.size() > 0 && stk.back() != u) {
            int v = stk.back();
            scc.push_back(v);
            stackMember[v] = false;
            stk.pop_back();
        }
        scc.push_back(u);
        stackMember[u] = false;
        stk.pop_back();
        sccs.push_back(scc);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> cost[i];
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        edges[u].push_back(v);
    }
    int time = 0;
    for (int i = 1; i <= n; i++) {
        if (!isVisited[i]) {
            tarjanSCC(i, edges, sccs, stk, low, disc, stackMember, isVisited, time);
        }
    }
    for (int i = 0; i < sccs.size(); i++) {
        long long minCostInScc = LLONG_MAX;
        long long cntMinCost = 0;
        for (auto u : sccs[i]) {
            minCostInScc = min(minCostInScc, cost[u]);
        }
        for (auto u : sccs[i]) {
            if (cost[u] == minCostInScc) cntMinCost++;
        }
        minCost += minCostInScc;
        ways = (ways * cntMinCost) % MOD;
    }
    cout << minCost << " " << ways << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
