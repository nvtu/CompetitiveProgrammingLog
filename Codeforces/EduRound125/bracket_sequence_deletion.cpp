#include <iostream>
using namespace std;

int t, n;
string s;

void solve() {
    int operation = 0, r = 0;;
    int i = 1;
    while (i<n) {
        if (s[i-1] == '(') operation++, i+=2, r+=2;
        else if (s[i-1] == ')') {
            if (s[i] == ')') operation++, i+=2, r+=2;
            else {
                int j = i+1;
                while (j<n) {
                    if (s[j] == ')') {
                        operation++;
                        r += j-(i-1)+1;
                        break;
                    }
                    j++;
                }
                i = j+2;
            }
        }
    }
    r = n-r;
    cout << operation << " " << r << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        solve();
    }
    return 0;
}

