#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);
int t, n, k, a;
map<int, int> cnt;
map<int, vector<int> > temp;

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cnt.clear();
        temp.clear();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a;
            cnt[a]++;
        }
        for (auto &p : cnt) {
            if (p.second % 2) {
                int val = p.first % k;
                temp[val].push_back(p.first);
            }
        }
        int count = 0;
        for (auto &p : temp) {
            sort(p.second.begin(), p.second.end());
            if (p.second.size() % 2) {
                count++;
                map<int, int> pf, sf;
                int mmin = INT_MAX;
                int sum = 0;
                for (int i = 1; i < p.second.size(); i += 2) {
                    sum += (p.second[i] - p.second[i - 1]) / k;
                    pf[i] = sum;
                }
                mmin = sum;
                sum = 0;
                for (int i = p.second.size() - 1; i >= 1; i -= 2) {
                    sum += (p.second[i] - p.second[i - 1]) / k;
                    sf[i - 1] = sum;
                }
                for (int i = 2; i < p.second.size() - 1; i += 2) {
                    mmin = min(mmin, pf[i - 1] + sf[i + 1]);
                }
                mmin = min(mmin, sum);
                ans += mmin;
            } else {
                for (int i = 0; i < p.second.size(); i += 2) {
                    ans += (p.second[i + 1] - p.second[i]) / k;
                }
            }
        }
        if (count > (n % 2)) ans = -1;
        cout << ans << endl;
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
