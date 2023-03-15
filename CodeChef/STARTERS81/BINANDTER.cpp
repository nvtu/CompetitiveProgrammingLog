#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

int T, N;

bool isPowerOfTwo(int n) {
    return (n && !(n & (n - 1)));
}

bool isPowerOfThree(int n) {
    long long res = 1;
    while (res < n) {
        res *= 3;
    }
    if (res == n || res == 1) return true;
    return false;
}

long long powX(long long a, int n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
}

int findMaxPow(int target, int base, int mu) {
    long long a = powX(base, mu);
    while (a > target && mu > 0) {
        mu--;
        a = powX(base, mu);
    }
    return mu;
}

void solve() {
    cin >> T;
    while (T--) {
        cin >> N;
        int mp2 = 31, mp3 = 20;
        int ans = 0;
        while (N) {
            int cnt2 = 0, cnt3 = 0;
            // Work with pow2
            mp3 = findMaxPow(N, 3, mp3);
            mp2 = findMaxPow(N, 2, mp2);
            int base = 3;
            long long a = powX(base, mp3);
            long long mu = mp3;
            if (powX(2, mp2) > powX(3, mp3)) {
                a = powX(2, mp2);
                base = 2;
                mu = mp2;
            }
            for (int i=mu; i>=0 && N; i--) {
                a = powX(base, i);
                if (i == 0) a = 0;
                long long remain = N - a;
                if (remain == 0) {
                    N = 0;
                    ans++;
                }
                else {
                    if (isPowerOfThree(remain) || isPowerOfTwo(remain)) {
                        N = 0;
                        if (i == 0) ans++;
                        else ans += 2;
                    }
                }
            }
            if (N) {
                N -= powX(base, mu);
                ans++;
            }
        }
        cout << ans << endl;
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
