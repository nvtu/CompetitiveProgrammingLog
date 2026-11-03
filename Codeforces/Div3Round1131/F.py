import sys

data = sys.stdin.buffer.read().split()
t = int(data[0])
index = 1
mod = 998244353
while t > 0:
    t -= 1
    n, m = map(int, data[index : index + 2])
    dp = [0] * (m + 3)
    dp[m + 2] = 1
    ans = 0
    for i in range(1, n):
        s = (dp[2] + dp[3]) % mod
        l, r = 2, 3
        for j in range(2, m + 3):
            temp = s
            s += mod - dp[l]
            l += 1
            r += 1
            if r < m + 3:
                s += dp[r]
            r += 1
            if r < m + 3:
                s += dp[r]
            s %= mod
            dp[j] = temp

        ans = (ans + dp[2]) % mod
    index += 2
    sys.stdout.write(f"{ans}\n")
