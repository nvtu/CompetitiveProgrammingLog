#include <bits/stdc++.h>
using namespace std;


int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int a = stoi(s, 0, 2);
    a >>= 1;
    cout << bitset<4>(a).to_string() << endl;
    return 0;
}

