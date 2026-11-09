import sys

data = sys.stdin.buffer.read().split()
t = int(data[0])
index = 1
while t > 0:
    t -= 1
    n = int(data[index])
    a = list(map(int, data[index + 1 : index + 1 + n]))
    index += n + 1
    a.sort()
    median = a[n >> 1] if n & 1 else (a[n >> 1] + a[(n >> 1) - 1]) >> 1
    lock_cost, step_cost, mmax = 0, 0, 0
    for i in range(n):
        if a[i] >= median:
            break
        lock_cost += median - a[i]
        mmax = max(mmax, median - a[i])
    step_cost += mmax
    mmax = 0
    for i in range(n - 1, -1, -1):
        if a[i] <= median:
            break
        lock_cost += a[i] - median
        mmax = max(mmax, a[i] - median)
    step_cost += mmax
    sys.stdout.write(f"{lock_cost} {step_cost}\n")
