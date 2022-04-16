#include <bits/stdc++.h>
using namespace std;

string S;
bool v[12];

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> S;
    for (int i=0; i<S.size(); i++) {
        int c = S[i] - '0';
        v[c] = true;
    }
    for (int i=0; i<10; i++) {
        if (v[i] == false) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}

