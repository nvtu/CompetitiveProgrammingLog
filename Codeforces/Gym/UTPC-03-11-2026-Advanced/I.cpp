#include <bits/stdc++.h>
using namespace std;
#define sqr(x) (x) * (x)
#define print(x, n)                                  \
    for (int i = 0; i < n; i++) cout << x[i] << " "; \
    cout << endl;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int n, m, k;

struct DoubleHash {
    static const long long MOD1 = (long long)1e7;
    static const long long MOD2 = (long long)1e9;
    static const long long BASE = 911382323;
    vector<long long> h1, h2, p1, p2;
    DoubleHash() {}
    DoubleHash(const vector<int>& s) {
        int n = s.size();
        for (int i = 0; i < n + 1; i++) {
            h1.push_back(0);
            h2.push_back(0);
            p1.push_back(1);
            p2.push_back(1);
        }
        for (int i = 0; i < n; i++) {
            long long v = s[i] + 1LL;
            h1[i + 1] = (h1[i] * BASE + v) % MOD1;
            h2[i + 1] = (h2[i] * BASE + v) % MOD2;
            p1[i + 1] = (p1[i] * BASE) % MOD1;
            p2[i + 1] = (p2[i] * BASE) % MOD2;
        }
    }
    pair<long long, long long> get(int l, int r) const {
        long long x1 = ((h1[r] - h1[l] * p1[r - l]) % MOD1 + MOD1) % MOD1;
        long long x2 = ((h2[r] - h2[l] * p2[r - l]) % MOD2 + MOD2) % MOD2;
        return {x1, x2};
    }
};

void solve() {
    cin >> n >> m >> k;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    a[n] = b[m] = k + 1;
    DoubleHash HA(a), HB(b);
    string ans = "";
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            ans += "A";
            i++;
        } else if (a[i] > b[j]) {
            ans += "B";
            j++;
        } else {
            int l = 0, r = min(n - i, m - j), pos = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (HA.get(i, i + mid) != HB.get(j, j + mid)) {
                    pos = mid - 1;
                    r = mid - 1;
                } else
                    l = mid + 1;
            }
            bool take_a;
            if (pos == -1) {
                take_a = (n - i > m - j);
            } else {
                take_a = (a[i + pos] < b[j + pos]);
            }
            if (take_a)
                ans += "A", i++;
            else {
                ans += "B", j++;
            }
        }
    }
    while (i < n) ans += "A", i++;
    while (j < m) ans += "B", j++;
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
