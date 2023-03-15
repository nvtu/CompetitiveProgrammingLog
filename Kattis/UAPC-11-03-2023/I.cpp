#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(40);
const long long MOD = int(1e9+7);

int n, m, p;
priority_queue<long long, vector<long long>, greater<long long> > c[MAX_SIZE];
vector<string> names;
map<string, int> player;
long long x;
string name;

void solve() {
    cin >> n >> m >> p; 
    for (int i=0; i<n; i++) {
        cin >> name;
        names.push_back(name);
        player[name] = i;
        for (int j=0; j<m; j++) {
            cin >> x;
            c[i].push(x);
        }
    }

    int totalTurn = n * m;
    vector<string> ans;

    vector<string> loser;
    while (totalTurn > 0) {
        totalTurn--;

        long long mmin = LLONG_MAX;  
        for (int i=0; i<n; i++) {
            if (c[i].empty()) continue;
            long long sc = c[i].top();
            if (mmin >= sc) {
                if (mmin > sc) loser.clear();
                loser.push_back(names[i]);
            }
            mmin = min(mmin, sc);
        }

        if ((int) loser.size() > 1) {
            sort(loser.begin(), loser.end());
        }
        name = loser[0];
        int idx = player[name];
        c[idx].pop();
        if (c[idx].empty()) {
            ans.push_back(name);
        }

        for (int i=0; i<n; i++) {
            if (i == idx || c[i].empty()) continue;
            long long newScore = c[i].top() + p;
            c[i].pop();
            c[i].push(newScore);
        }

        loser.clear();
    } 

    for (auto t: ans) {
        cout << t << " ";
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
