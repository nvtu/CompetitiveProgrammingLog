#include <bits/stdc++.h>
using namespace std;

int N;
string s[105], t[105];

int main() {
   // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    int cnt = 0;
    for (int i=0; i<N; i++) cin >> s[i] >> t[i];
    for (int i=0; i<N; i++) {
        string u = "", v = "";
        for (int j=0; j<N; j++) {
            if (i == j) continue;
            if (s[i] == s[j]) u = s[j];
            else if (s[i] == t[j]) u = t[j];
            if (t[i] == s[j]) v = s[j];
            else if (t[i] == t[j]) v = t[j];
        }
    }
    cout << (cnt == N ? "Yes" : "No") << endl;
    return 0;
}

