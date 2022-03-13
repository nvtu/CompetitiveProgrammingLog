#include <bits/stdc++.h>
using namespace std;

string s;
stack<char> stk;
int ans = 0;

char mapBracket(char brk) {
    switch (brk) {
        case ']': return '[';
        case '}': return '{';
        case ')': return '(';
        case '>': return '<';
    }
    return '\0';
}

int main () {
    // freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> s;
    for (int i=0; i < (int) s.size(); i++) {
        if (s[i] == '[' || s[i] == '{' || s[i] == '<' || s[i] == '(') stk.push(s[i]);
        else {
            if (stk.empty()) {
                cout << "Impossible" << endl;
                return 0;
            }
            else if (stk.top() != mapBracket(s[i])) ans++;
            stk.pop();
        }
    }
    if (stk.empty()) cout << ans << endl;
    else cout << "Impossible" << endl;
    return 0;
}