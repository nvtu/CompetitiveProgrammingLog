import sys

data = sys.stdin.buffer.read().split()
n, s = map(int, data[:2])
t = list(map(float, data[2:]))
t.sort(reverse=True)

if n == 1:
    ans = t[0]
else:
    empty_s = s - n
    if empty_s >= n - 1:
        ans = t[0]
    else:
        ans = float("inf")
        for x in range(empty_s + 1):
            cur = 0 if x == 0 else t[0]
            remain_s = s - 2 * x + 1
            remain_n = n - x
            l, r, k = 1, (remain_n + 1) // 2, 1
            while l <= r:
                m = (l + r) >> 1
                r_s = remain_s - 3 * m
                r_n = remain_n - 2 * m
                if r_n >= 0 and r_s >= r_n:
                    k = m
                    l = m + 1
                else:
                    r = m - 1
            cur = max(cur, t[x] / 0.6)
            if x + 2 * k < n:
                cur = max(cur, t[x + 2 * k] / 0.3)
            ans = min(ans, cur)

sys.stdout.write(f"{ans:.6f}\n")
