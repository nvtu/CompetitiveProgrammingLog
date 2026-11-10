import sys

MOD = 998244353
data = sys.stdin.buffer.read().split()
t = int(data[0])
index = 1
while t > 0:
    t -= 1
    n = int(data[index])
    a = list(map(int, data[index + 1 : index + 1 + n]))
    index += n + 1

    s = [True]
    for i in range(1, n):
        if a[i] == a[i - 1] + 1:
            s.append(True)
        elif a[i] == a[i - 1] + 2:
            s.append(False)
            s.append(True)
        else:
            s.append(False)
            s.append(False)
            s.append(True)
    s.append(False)

    m = len(s)
    ans = (((n + 1) * n) >> 1) % MOD
    dp1, dp2 = [1] * (m + 1), [0] * (m + 1)
    for i in range(1, m):
        if s[i - 1]:
            dp2[i + 1] = 1
        if i >= 2 and s[i - 1] and s[i - 2]:
            dp1[i + 1] += dp1[i - 2]
            dp2[i + 1] += dp2[i - 2]
        if i >= 3 and s[i - 1] and s[i - 2] and s[i - 3]:
            dp1[i + 1] += dp1[i - 3]
            dp2[i + 1] += dp2[i - 3]
        dp1[i + 1] %= MOD
        dp2[i + 1] %= MOD
        ans += dp1[i + 1] + dp2[i + 1] - 1
    for i in range(1, m):
        if s[i - 1]:
            ans = (ans + dp1[i - 1] + dp2[i - 1]) % MOD
    s.append(False)
    s.append(False)
    for i in range(m):
        if s[i]:
            ans -= 2
        if s[i] and s[i + 1]:
            ans -= 1
        if s[i] and s[i + 2]:
            ans -= 1
    ans = (ans + MOD) % MOD
    sys.stdout.write(f"{ans}\n")
