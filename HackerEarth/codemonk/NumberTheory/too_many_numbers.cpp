#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


long long n, m, l, r, k;
vector<long long> ans, temp;

void output_ans() {
    cout << ans.size() << endl;
    if (k < 0) cout << -1 << endl;
    else for (auto x: ans) cout << x << " ";
}

void consider_adding(long long L, long long R, long long target) {
    if (target == m) return;
	if (target >= L && target <= R) {
		temp.push_back(target);	
	}
}
	

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> m >> l >> r >> k;
    long long rem = n % m; 
    long long target = n - rem;
    if (!target) {
        if (n > r) {
            if (k > 0) cout << -1 << endl;
            else cout << 0 << endl;
        }
        else {
            l = max(l, n+1);
            if (r-l+1 > k) {
                cout << r-l+1 << endl;
                cout << -1 << endl;
            }
            else {
                for (long long i = l; i <= r; i++) {
                    if (i == m) continue;
                    ans.push_back(i);
                    k--;
                }
                output_ans();
            }
        }
    }
    else {
        for (long long div = 1; div < sqrt(target); div++) {
            if (target % div == 0) {
                long long rdiv = target / div;
                consider_adding(l, r, div);
                consider_adding(l, r, rdiv);
            }
        }
        sort(temp.begin(), temp.end());
        for (auto x: temp) {
            if (n % x == rem) {
                ans.push_back(x);
                k--;
            }
        }
        output_ans();
    }
    return 0; 
}
