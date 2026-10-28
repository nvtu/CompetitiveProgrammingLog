import sys

data = sys.stdin.buffer.read().split()
n, m, k = list(map(int, data[:3]))
xs = [int(v) * k for v in data[3 : 3 + 2 * n : 2]]
ys = [int(v) * k for v in data[4 : 3 + 2 * n : 2]]

min_x = min(xs)
min_y = min(ys)

if max(xs) - min_x > m or max(ys) - min_y > m:
    print(-1)
else:
    out = [f"{x - min_x} {y - min_y}" for (x, y) in zip(xs, ys)]
    sys.stdout.write("\n".join(out))
