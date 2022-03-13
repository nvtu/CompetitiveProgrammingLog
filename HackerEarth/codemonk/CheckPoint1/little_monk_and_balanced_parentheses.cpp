#include <iostream>
#include <vector>
using namespace std;
const int SZ = int(2e5+5);

int N, x[SZ], stk[SZ], k = 0, ans = 0;
vector<pair<int, int> > res;

void update_result(int start, int end) {
    int sz = int(res.size());
    if (sz == 0) res.push_back({start, end});
    else { 
        if (start-1 == res[sz-1].second) res[sz-1].second = end;
        else if (start+1 == res[sz-1].first && end-1 == res[sz-1].second) {
            res.pop_back();
            update_result(start, end);
        }
        else res.push_back({start, end});
    }
}


int main() {
    freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i=0; i<N; i++) cin >> x[i];
    int i = 0;
    while (i < N) {
        while (i < N && x[i] > 0) stk[++k] = i++;
        while (i < N && x[i] < 0) {
            if (k > 0) {
                if (x[i] + x[stk[k]] == 0) update_result(stk[k--], i);
                else k = 0;
            }
            i++;
        }
    }
//    for (auto r: res) cout << r.first << " " << r.second << endl;
    for (auto r: res) ans = max(ans, r.second - r.first + 1);
    cout << ans << endl;
    return 0;
}
