#include <bits/stdc++.h>
using namespace std;

string S;
stack<int> stk;

bool isNumberInRange(char c) {
    int x = c - '0';
    return x >= 2 && x <= 9;
}

void solve() {
    int N = S.length();
    for (int i=0; i<N; i++) {
        if (S[i] == 'C') stk.push(12);
        else if (S[i] == 'H') stk.push(1);
        else if (S[i] == 'O') stk.push(16);
        else if (S[i] == '(') stk.push(0);
        else if (S[i] == ')') {
            int mass = 0;
            while (stk.size() && stk.top() > 0) {
                mass += stk.top();
                stk.pop();
            }
            stk.pop();
            stk.push(mass);
        }
        else {
            int mul = S[i] - '0';
            int mass = stk.top();
            stk.pop();
            stk.push(mass * mul);
        }
    }
    int ans = 0;
    while (stk.size()) {
        ans += stk.top();
        stk.pop();
    }
    cout << ans << endl;
}

int main() {
//    freopen("input.txt", "r", stdin); 
    ios::sync_with_stdio(false);
    cin >> S;
    solve();
    return 0;
}

