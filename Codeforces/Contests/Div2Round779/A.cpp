#include <bits/stdc++.h>
using namespace std;

int n, t;
string s;

int main() {
//    freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int ans = 0;
        if (n == 1) ans = 0;
        if (n == 2 && s == "00") ans = 2;
        else {
            string t = s.substr(0, 2);
            int i = 2;
            while (i < n) {
                t += s[i];
                if (t == "000") ans += 4, t = "10";
                else if (t == "001") ans += 2, t = "01";
                else if (t == "010") ans++, t = "10";
                else if (t == "100") ans += 2, t = "10"; 
                else t = t.substr(1, 2);
                i++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

