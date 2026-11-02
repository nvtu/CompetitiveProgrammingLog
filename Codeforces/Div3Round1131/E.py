import sys

data = sys.stdin.buffer.read().split()
t = int(data[0])
index = 1
while t > 0:
    t -= 1
    n = int(data[index])
    a = list(map(int, data[index + 1 : index + 1 + n]))
    c = -1
    for i in range(n):
        c *= -1
        a[i] = c * a[i]
    a.sort()
    ans = sum(a[n >> 1 :]) - sum(a[: n >> 1])
    index += n + 1
    sys.stdout.write(f"{ans}\n")
