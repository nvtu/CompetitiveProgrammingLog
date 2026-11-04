import sys

data = sys.stdin.buffer.read().split()
a = list(map(float, data[:3]))
r = [3, 3, 10]

qs = [a[i] / r[i] for i in range(3)]
max_q = max(qs)
ans = [(max_q - qs[i]) * r[i] for i in range(3)]

sys.stdout.write(f"{ans[0]:.6f} {ans[1]:.6f} {ans[2]:.6f}\n")
