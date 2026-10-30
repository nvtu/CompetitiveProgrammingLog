#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

long long gcd(long long a, long long b) {
    return !b ? a : gcd(b, a % b);
}

long long safe_lcm(long long a, long long b, long long limit) {
    long long lcm = min(a / gcd(a, b) * b, limit + 1);
    return lcm;
}

struct SegmentTree {
    int n;
    vector<long long> tree;
    SegmentTree() : n(0) {}
    SegmentTree(int n, const vector<long long>& a, long long limit) {
        this->n = n;
        tree.resize(n << 1);
        for (int i = 0; i < n; i++) {
            tree[i + n] = a[i];
        }
        for (int i = n - 1; i > 0; i--) {
            tree[i] = safe_lcm(tree[i << 1], tree[i << 1 | 1], limit);
        }
    }

    long long query(int l, int r, long long limit) {
        long long ans = 1;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = safe_lcm(ans, tree[l++], limit);
            if (r & 1) ans = safe_lcm(ans, tree[--r], limit);
        }
        return ans;
    }
};

void solve() {
    int n;
    long long t, C = 0, S = 0;
    vector<long long> a;
    cin >> n >> t;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    SegmentTree st = SegmentTree(n, a, t);
    for (int i = 0; i < n; i++) {
        int l = i, r = n - 1, pos = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            long long _lcm = st.query(i, mid + 1, t);
            if (_lcm <= t) {
                pos = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        if (pos != -1) {
            long long length = pos - i + 1;
            C += length;
            S += (length * (length + 1)) >> 1;
        }
    }
    cout << C << " " << S << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
