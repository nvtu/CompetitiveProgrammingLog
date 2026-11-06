import sys

data = sys.stdin.buffer.read().split()
t = int(data[0])
index = 1
while t > 0:
    t -= 1
    n = int(data[index])
    index += 1

    ans = 0
    for h in range(1, n):
        ans = max(ans, h * (n - h))
    sys.stdout.write(f"{ans}\n")
