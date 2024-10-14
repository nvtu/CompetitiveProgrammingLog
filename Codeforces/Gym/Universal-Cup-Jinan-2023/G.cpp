#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstdlib>
#include <set>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e6+5);
const long long MOD = int(1e9+7);
const double EPS = 1e-6;

int T, r, c;
bool visited[MAX_SIZE], reversed[MAX_SIZE];
vector<pair<int, bool> > g[MAX_SIZE];
string s[MAX_SIZE];
long long ans = 1;


void addEdge(int u, int v, bool reversed) {
    g[u].push_back(make_pair(v, reversed));
    g[v].push_back(make_pair(u, reversed));
}

void dfs(int u) {
    visited[u] = true;
    for (int i=0; i<g[u].size(); i++) {
        int v = g[u][i].first;
        if (!visited[v]) {
            reversed[v] = (reversed[u] ^ g[u][i].second);
            dfs(v);
        }
        else if (reversed[v] != (reversed[u] ^ g[u][i].second)) {
            ans = 0;
        }
    }
}

void reset() {
    for (int i=0; i<r; i++) g[i].clear();
}

long long countAnswer() {
    ans = 1;
    for (int i=0; i<r; i++) visited[i] = reversed[i] = false;
    for (int j=0; j<=c-1-j; j++) {
        vector<int> L, R;
        for (int i=0; i<r; i++) {
            if (s[i][j] == '1') L.push_back(i);
            if (s[i][c-1-j] == '1') R.push_back(i);
        }
        if (L.size() + R.size() > 2) return 0;
        if (j == c-1-j) continue;
        if (L.size() == 2) addEdge(L[0], L[1], true);
        else if (R.size() == 2) addEdge(R[0], R[1], true);
        else if (L.size() == 1 && R.size() == 1) addEdge(L[0], R[0], false);
    }
    visited[1] = false;
    for (int i=0; i<r; i++) {
        if (!visited[i]) {
            dfs(i);
            ans = (ans * 2) % MOD;
        }
    }
    return ans;
}


void solve() {
    cin >> T;
    while (T--) {
        cin >> r >> c;
        for (int i=0; i<r; i++) cin >> s[i];
        long long ans = countAnswer();
        reset();
        cout << ans << endl;
    }
}


int main() {
    // freopen("inp.txt", "r", stdin);

    //Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}