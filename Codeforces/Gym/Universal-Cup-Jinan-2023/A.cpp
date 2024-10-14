#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstdlib>
#include <set>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);
const double EPS = 1e-6;

int T;
string S;
stack<int> stk;

bool checkSameTypeBalanceBracketPair(char a, char b) {
    return (a == '(' && b == ')') || (a == ')' && b == '(') || 
        (a == '[' && b == ']') || (a == ']' && b == '[');
}

bool checkSameTypeBracket(char a, char b) {
    return checkSameTypeBalanceBracketPair(a, b) || (a == b);
}

bool check(vector<int> p) {
    vector<int> gap;
    for (int i=1; i<p.size(); i++) {
        gap.push_back(p[i] - p[i-1] - 1);
    }
    int cnt = 0;
    bool flag = false;
    for (int i=0; i<gap.size(); i++) {
        if (gap[i] % 2 == 0) {
            if (flag) return false;
            cnt++;
            flag = true;
        }
        else flag = false;
    }
    return cnt <= 2;
}

void solve() {
    cin >> T;
    while (T--) {
        cin >> S;
        string ans = "Yes";
        vector<int> pos[2];
        for (int i=0; i<S.length(); i++) {
            if (checkSameTypeBracket(S[i], '(')) {
                pos[0].push_back(i);
            }
        }
        for (int i=0; i<S.length(); i++) {
            if (checkSameTypeBracket(S[i], '[')) {
                pos[1].push_back(i);
            }
        }
        if (!check(pos[0]) || !check(pos[1])) {
            ans = "No";
        }
        cout << ans << endl;
    }
}


int main() {
    // freopen("inp.txt", "r", stdin);

    //Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}