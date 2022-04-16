#include <bits/stdc++.h>
using namespace std;

int Q, q;
long long x, c;
deque<pair<long long, long long> > d;

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> Q;
    while (Q--) {
        cin >> q;
        if (q == 1) {
            cin >> c >> x;
            d.push_back({x, c});
        }
        else {
            long long ans = 0;
            cin >> c;
            while (c > 0) {
                auto x = d.front();
                d.pop_front();
                long long mmin = min(x.first, c);
                c -= mmin, x.first -= mmin;
                ans += mmin * x.second;
                if (x.first > 0) d.push_front(x);
            }
            cout << ans << endl;
        }
    }
    return 0;
}

