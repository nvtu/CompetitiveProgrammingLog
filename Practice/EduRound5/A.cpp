#include <bits/stdc++.h>
using namespace std;

string a, b;

string removeTrailingZeros(string t) {
    if (t.size() == 1) return t;
    int index = 0;
    while (index < int(t.size()) && t[index] == '0') index++;
    if (index == t.size()) t = "0";
    else t = t.substr(index, t.size() - index);
    return t;
}

string compare(string t, string u) {
    if (t.size() > u.size()) return ">";
    else if (t.size() < u.size()) return "<";
    return (t > u ? ">" : (t < u ? "<" : "=")); 
}

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("test.txt", "r", stdin);
    cin >> a >> b;
    a = removeTrailingZeros(a);
    b = removeTrailingZeros(b);
    cout << compare(a, b) << endl;
    return 0;
}