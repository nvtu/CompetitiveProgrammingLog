#include <bits/stdc++.h>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);

int N, K, A, B;

void solve() {
    cin >> N >> K;
    vector<int> psum(N + 1, 0);
    for (int i = 0; i < K; i++) {
        cin >> A >> B;
        psum[A]++;
        psum[B + 1]--;
    }
    for (int i = 1; i <= N; i++) {
        psum[i] += psum[i - 1];
    }
    sort(psum.begin(), psum.end());
    cout << psum[N / 2 + 1] << endl;
}

int main() {
    freopen("stacking.in", "r", stdin);
    freopen("stacking.out", "w", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
