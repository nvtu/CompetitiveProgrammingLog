#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n;
string a, b;

int count_leaf_brackets(string x) {
    int m = x.size();
    int cnt = 0;
    for (int i = 0; i < m - 1; i++) {
        if (x[i] == '(' && x[i + 1] == ')') cnt++;
    }
    return cnt;
}

int count_outer_brackets(string x) {
    int m = x.size();
    vector<int> match(m, -1);
    stack<int> stk;
    for (int i = 0; i < m; i++) {
        if (x[i] == '(') {
            stk.push(i);
        } else {
            int j = stk.top();
            stk.pop();
            match[j] = i;
        }
    }
    int l = 0, r = m - 1, cnt = 0;
    while (match[l] == r) {
        l++, r--, cnt++;
    }
    return cnt;
}

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        bool ok = (count_leaf_brackets(a) == count_leaf_brackets(b)) && (count_outer_brackets(a) == count_outer_brackets(b));
        cout << (ok ? "YES" : "NO") << endl;
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
