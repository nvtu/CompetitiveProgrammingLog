#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(2e5 + 5);
const long long MOD = int(1e9 + 7);

int t, n, k, a[MAX_SIZE], b[MAX_SIZE], cnta[MAX_SIZE], cntb[MAX_SIZE];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        memset(cnta, 0, sizeof(cnta));
        memset(cntb, 0, sizeof(cntb));
        bool ok = true;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        queue<int> q;
        for (int i = 0; i < k; i++) {
            cnta[a[i]]++;
            if (b[i] != -1) {
                cntb[b[i]]++;
            }
        }
        for (int i = 0; i < k; i++) {
            int j = i + k;
            if (b[i] == -1) {
                if (i + k < n) {
                    bool filled = false;
                    for (int j = i + k; j < n; j += k) {
                        if (a[i] != a[j]) {
                            b[i] = a[i];
                            cntb[a[i]]++;
                            filled = true;
                            break;
                        } else {
                            if (b[j] != -1) {
                                b[i] = b[j];
                                cntb[b[i]]++;
                                filled = true;
                                break;
                            }
                        }
                    }
                    if (!filled) q.push(i);
                } else
                    q.push(i);
            }
        }
        for (int i = 0; i < k; i++) {
            if (cnta[a[i]] >= cntb[a[i]]) {
                int diff = cnta[a[i]] - cntb[a[i]];
                if (diff > 0) {
                    if (!q.empty()) {
                        int pos = q.front();
                        q.pop();
                        b[pos] = a[i];
                        cntb[a[i]]++;
                    } else {
                        ok = false;
                    }
                }
            } else
                ok = false;
        }
        for (int i = 0; i < k; i++) {
            if (cntb[b[i]] != cnta[b[i]]) ok = false;
        }
        if (ok) {
            for (int i = k; i < n; i++) {
                // Remove
                int j = i - k;
                cnta[a[j]]--;
                cntb[b[j]]--;

                // Add
                cnta[a[i]]++;
                if (b[i] != -1) {
                    cntb[b[i]]++;
                } else {
                    if (cnta[a[i]] != cntb[a[i]]) {
                        cntb[a[i]]++;
                        b[i] = a[i];
                    } else if (cnta[a[j]] != cntb[a[j]]) {
                        cntb[a[j]]++;
                        b[i] = a[j];
                    } else if (cnta[b[j]] != cntb[b[j]]) {
                        cntb[b[j]]++;
                        b[i] = b[j];
                    }
                }

                // Check again
                if (cnta[a[i]] != cntb[a[i]] || cnta[a[j]] != cntb[a[j]] || cnta[b[j]] != cntb[b[j]]) {
                    ok = false;
                    break;
                }
            }
        }
        string ans = (ok ? "YES" : "NO");
        cout << ans << endl;
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
