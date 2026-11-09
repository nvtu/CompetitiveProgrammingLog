import sys

data = sys.stdin.buffer.read().split()
t = int(data[0])
index = 1
while t > 0:
    t -= 1
    n = int(data[index])
    a = sorted(
        list(map(lambda x: 1 << int(x), data[index + 1 : index + 1 + n])), reverse=True
    )
    index += n + 1
    h, w = 0, 0
    for v in a:
        if h <= w:
            h += v
        else:
            w += v
    ans = h * w
    sys.stdout.write(f"{ans}\n")
