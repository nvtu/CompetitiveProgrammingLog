#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(3e5 + 5);
const long long MOD = int(1e9 + 7);

int t, k, n, u, v, cur_to[MAX_SIZE];
long long a[MAX_SIZE], ans[MAX_SIZE], acc_sum[MAX_SIZE], sum;
vector<int> e[MAX_SIZE];
// first is length of the longest path, second is the "to" leaf node
pair<int, int> fi[MAX_SIZE], se[MAX_SIZE], leaf[MAX_SIZE];
set<pair<long long, int>> s;
set<pair<long long, int>>::iterator it;

void init_default_settings(int u, int parent) {
    fi[u] = {0, -u};
    for (auto v : e[u]) {
        if (v != parent) {
            init_default_settings(v, u);
            pair<int, int> temp = fi[v];
            temp.first++;
            if (temp > se[u]) {
                swap(temp, se[u]);
            }
            if (se[u] > fi[u]) {
                swap(se[u], fi[u]);
            }
        }
    }
}

void init_default_root_propagation() {
    int root = 1;
    sum = ans[root] = 0;
    ans[root] += a[root];
    for (int i = 2; i < n + 1; i++) {
        // Propagate value to longest leaf nodes
        cur_to[i] = -fi[i].second;
        acc_sum[cur_to[i]] += a[i];
    }
    for (int i = 2; i < n + 1; i++) {
        s.insert({-acc_sum[i], i});
    }
    it = s.begin();
    for (int i = 0; i < k - 1; i++) {
        ans[root] -= it->first;
        sum -= it->first;
        it++;
    }
    it--;
}

void remove_from_set(int u) {
    pair<long long, int> x = {-acc_sum[u], u};
    if (*it >= x) {
        it++;
        sum -= it->first;
        sum -= acc_sum[u];
    }
    s.erase(x);
}

void insert_into_set(int u) {
    pair<long long, int> x = {-acc_sum[u], u};
    s.insert(x);
    if (*it >= x) {
        sum += it->first;
        sum += acc_sum[u];
        it--;
    }
}

void update_cur_to(int u) {
    remove_from_set(cur_to[u]);
    acc_sum[cur_to[u]] -= a[u];
    insert_into_set(cur_to[u]);
    cur_to[u] = 0;
}

void set_new_cur_to(int u, int to) {
    cur_to[u] = to;
    remove_from_set(cur_to[u]);
    acc_sum[cur_to[u]] += a[u];
    insert_into_set(cur_to[u]);
}

void propagate_rerooting(int u, int parent) {
    // Update when rerooting
    if (parent != 0) {
        update_cur_to(u);
        remove_from_set(u);
        insert_into_set(parent);
        set_new_cur_to(parent, -leaf[parent].second);
        ans[u] = sum + a[u];
    }
    for (auto v : e[u]) {
        if (v != parent) {
            pair<int, int> temp = leaf[parent];
            temp.first++;
            if (fi[u].second == fi[v].second) {
                leaf[u] = max(temp, se[u]);
            } else {
                leaf[u] = max(temp, fi[u]);
            }
            propagate_rerooting(v, u);
        }
    }
    // Reset
    if (parent != 0) {
        insert_into_set(u);
        set_new_cur_to(u, -fi[u].second);
        update_cur_to(parent);
        remove_from_set(parent);
    }
}

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        long long mmax = 0;
        sum = 0;
        leaf[0] = {-MAX_SIZE, 0};
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mmax = max(mmax, a[i]);
            sum += a[i];
            ans[i] = acc_sum[i] = 0LL;
            e[i].clear();
            fi[i] = se[i] = leaf[i] = {-MAX_SIZE, 0};
        }
        s.clear();
        int cnt_leaves = 0;
        for (int i = 0; i < n - 1; i++) {
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
            if (e[u].size() == 1)
                cnt_leaves++;
            else if (e[u].size() == 2)
                cnt_leaves--;
            if (e[v].size() == 1)
                cnt_leaves++;
            else if (e[v].size() == 2)
                cnt_leaves--;
        }

        if (k >= cnt_leaves) {
            mmax = sum;
        } else if (k > 1 && k < cnt_leaves) {
            // if (k > 1) {
            init_default_settings(1, 0);
            init_default_root_propagation();
            propagate_rerooting(1, 0);
            for (int i = 1; i < n + 1; i++) {
                mmax = max(mmax, ans[i]);
            }
        }
        cout << mmax << endl;
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
