#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int t;
string s;

int get_sum_digit(int n) {
    int ans = 0;
    while (n > 0) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int get_sum_digit_from_str(string t) {
    int ans = 0;
    for (int i = 0; i < t.size(); i++) {
        ans += t[i] - '0';
    }
    return ans;
}

void solve() {
    cin >> t;
    while (t--) {
        cin >> s;
        int n = s.size();
        if (n == 1) {
            cout << s << endl;
            continue;
        }
        vector<int> cnt_digit(10, 0);
        int sum_digit = get_sum_digit_from_str(s);
        for (int i = 0; i < n; i++) {
            cnt_digit[s[i] - '0']++;
        }
        for (int num = 1; num <= 9 * n; num++) {
            int temp = num;
            string ans = to_string(num);
            vector<int> need_cnt_digit(10, 0);
            while (temp > 9) {
                temp = get_sum_digit(temp);
                ans += to_string(temp);
            }
            int current_sum_digit = get_sum_digit_from_str(ans);
            for (int i = 0; i < ans.size(); i++) {
                need_cnt_digit[ans[i] - '0']++;
            }
            bool ok = true;
            for (int i = 0; i < 10; i++) {
                if (need_cnt_digit[i] > cnt_digit[i]) {
                    ok = false;
                    break;
                }
            }
            if (sum_digit - current_sum_digit != num) ok = false;
            if (ok) {
                string prefix = "";
                for (int i = 9; i >= 0; i--) {
                    for (int j = 0; j < cnt_digit[i] - need_cnt_digit[i]; j++) {
                        prefix += to_string(i);
                    }
                }
                cout << prefix << ans << endl;
                break;
            }
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
