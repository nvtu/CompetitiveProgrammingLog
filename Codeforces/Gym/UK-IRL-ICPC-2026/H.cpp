#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int n, k;
string s;

void solve() {
    cin >> k >> n;
    unordered_map<string, int> id;
    vector<string> names;
    vector<int> seq(n);
    for (int i = 0; i < n; i++) {
        cin >> s;
        auto it = id.find(s);
        if (it == id.end()) {
            int new_id = names.size();
            id[s] = new_id;
            names.push_back(s);
            seq[i] = new_id;
        } else
            seq[i] = it->second;
    }
    int m = names.size();
    for (int i = m, c = 0; i < k; i++) {
        s = "dummy";
        while (id.count(s)) {
            s = "dummy" + string(1, 'a' + c++);
        }
        id[s] = i;
        names.push_back(s);
    }
    // Initialize weights
    long long w[k][k], deg[k];
    memset(w, 0, sizeof(w));
    memset(deg, 0, sizeof(deg));
    for (int i = 0; i + 1 < n; i++) {
        int u = seq[i], v = seq[i + 1];
        if (u != v) {
            w[u][v]++, w[v][u]++;
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            deg[i] += w[i][j];
        }
    }
    // Compute cut[S]
    int L = 1 << k;
    vector<long long> cut(L, 0), dp(L, LLONG_MAX);
    vector<int> from(L);
    for (int S = 1; S < L; S++) {
        int v = __builtin_ctz(S);
        int R = S & (S - 1);
        long long in = 0;
        for (int j = 0; j < k; j++) {
            if ((R >> j) & 1) in += w[v][j];
        }
        cut[S] = cut[R] + deg[v] - (in << 1);
    }
    // Begin dp
    dp[0] = 0;
    for (int S = 1; S < L; S++) {
        for (int j = 0; j < k; j++) {
            if ((S >> j) & 1) {
                long long c = dp[S ^ (1 << j)] + cut[S];
                if (c < dp[S]) {
                    dp[S] = c;
                    from[S] = j;
                }
            }
        }
    }
    vector<int> ans;
    int S = L - 1;
    while (S) {
        ans.push_back(from[S]);
        S ^= (1 << from[S]);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < k; i++) {
        cout << names[ans[i]] << " ";
    }
    cout << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
