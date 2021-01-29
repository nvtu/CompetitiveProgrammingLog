#include <bits/stdc++.h>
using namespace std;

const int MAX_ITEMS = int(1e3+5);
const int MMOD = int(1e9+7);
int t, n, k, numFollowers;
long long fact[MAX_ITEMS];
map<int, long long> cnt;
vector<int> uniqueNumFollowers;


long long computePow(long long n, long long mu) {
    if (n == 0) return 0;
    long long ans = 1;
    while (mu > 0) {
        if (mu % 2) {
            ans = (ans * n) % MMOD;
            mu--;
        }
        n = (n * n) % MMOD;
        mu >>= 1;
    }
    return ans;
}


long long computeCombinatorics(long long k, long long n) {
    long long ans = ((fact[n] * computePow(fact[k], MMOD - 2) % MMOD) * computePow(fact[n-k], MMOD - 2)) % MMOD;
    return ans;
}


int main() {
    // freopen("E.txt", "r", stdin);
    fact[0] = fact[1] = 1;
    for (long long i=2; i<MAX_ITEMS; i++) fact[i] = (fact[i-1] * i) % MMOD;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i=0; i<n; i++) {
            cin >> numFollowers;
            uniqueNumFollowers.push_back(numFollowers);
            cnt[numFollowers]++;
        }
        sort(uniqueNumFollowers.begin(), uniqueNumFollowers.end(), greater<int>());
        vector<int>::iterator it = unique(uniqueNumFollowers.begin(), uniqueNumFollowers.end());
        uniqueNumFollowers.resize(distance(uniqueNumFollowers.begin(), it));
        long long ans = 1;
        for (int i=0; i<int(uniqueNumFollowers.size()); i++) {
            numFollowers = uniqueNumFollowers[i];
            if (cnt[numFollowers] >= k) {
                ans = computeCombinatorics(k, cnt[numFollowers]);
                break;
            }
            else k -= cnt[numFollowers];
        }
        cout << ans << endl;
        cnt.clear();
        uniqueNumFollowers.clear();
    }
    return 0;
}
