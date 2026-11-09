import sys

data = sys.stdin.buffer.read().split()
t = int(data[0])
index = 1
while t > 0:
    t -= 1
    rs = list(map(int, data[index : index + 3]))
    d = [(r, a) for a, r in zip(["P", "R", "S"], rs)]
    d.sort(reverse=True)
    ans = d[0][1] * sum(rs)
    index += 3
    sys.stdout.write(ans + "\n")
