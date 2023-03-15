#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e3+5);
const long long MOD = int(1e9+7);

int b;
string s;
string a[MAX_SIZE];
vector<pair<long long, size_t>> pos;

void input() {
    cin >> b;
    for (int i=0; i<b; i++) {
        cin >> a[i];
    }
    cin >> s;
}

long long power(long long a, long long b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    long long tmp = power(a, b/2);
    if (b % 2 == 0) return tmp * tmp;
    return tmp * tmp * a;
}

void solve(){
    input();
    for (int i=0; i<b; i++) {
        size_t found = s.find(a[i]);
        while (found != string::npos) {
            pos.push_back({found, i});
            found = s.find(a[i], found+1); 
        }
    }
    sort(pos.begin(), pos.end());
    int cur = 0, len = 0;
    long long ans = 0, factor = 0;
    auto it = pos.begin();
    while (it != pos.end()) {
        if (cur == it->first) {
            factor++;
            cur += a[it->second].size();
            it++;
        }
        else
            pos.erase(it);
    }
    for (auto it = pos.begin(); it != pos.end(); it++) {
        ans += power(b, factor-1) * (it->second);
        factor--;
    }
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
