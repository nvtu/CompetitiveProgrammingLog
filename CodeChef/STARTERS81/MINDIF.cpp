#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

int T, N, A;
deque<int> v;

bool checkIncreasing(deque<int> v) {
    int len = (int) v.size();
    for (int i=1; i<len; i++) {
        if (v[i] < v[i-1]) return false;
    }
    return true;
}

bool checkDecreasing(deque<int> v) {
    int len = (int) v.size();
    for (int i=1; i<len; i++) {
        if (v[i] > v[i-1]) return false;
    }
    return true;
}

bool check(deque<int> v) {
    return !(checkIncreasing(v) || checkDecreasing(v));
}

int minDiff(deque<int> v) {
    int ans = INT_MAX;
    int len = (int) v.size();
    if (!check(v)) return ans;
    for (int i=1; i<len; i++) {
        ans = min(ans, abs(v[i] - v[i-1]));
    }
    return ans;
}

void solve() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i=0; i<N; i++) {
            cin >> A;
            v.push_back(A);
        }
        sort(v.begin(), v.end());
        int ans = INT_MAX;

        // Case [S_n, S_1, S_2, ..., S_{n-1}]
        v.push_front(v.back());
        v.pop_back();
        ans = min(ans, minDiff(v));

        // Case [S_2, ..., S_n, S_1]
        for (int i=0; i<2; i++) {
            v.push_back(v.front());
            v.pop_front();
        }
        int mmin = minDiff(v);
        if (mmin > ans) {
            for (int i=0; i<2; i++) {
                v.push_front(v.back());
                v.pop_back();
            }
        }
        else ans = mmin;

        if (ans == INT_MAX) {
            cout << -1 << endl;
            v.clear();
        }
        else {
            while (!v.empty()) {
                cout << v.front() << " ";
                v.pop_front();
            }
            cout << endl;
        }
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
