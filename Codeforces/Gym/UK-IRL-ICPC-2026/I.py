import sys, math

data = sys.stdin.buffer.read().split()
n = int(data[0])

a, b = -1, -1
s = math.inf


def compute(x: int, y: int) -> tuple[int, int]:
    res = [x * (y + 1), x * y * (y + 1)]
    s = sum(res)
    if res[0] == res[1]:
        res = [-1, -1]
        s = math.inf
    for k in range(1, int(math.sqrt(y)) + 1):
        if y % k == 0:
            for _ in range(2):
                k = y // k
                temp = [x * (k * x + y), y * (x + y // k)]
                temp_s = sum(temp)
                if temp_s < s and temp[0] != temp[1]:
                    s = temp_s
                    res = temp

    return (min(res), max(res))


for i in range(1, int(math.sqrt(n)) + 1):
    if n % i == 0:
        candidates = [
            compute(i, n // i),
            compute(n // i, i),
        ]
        candidates = [item for item in candidates if item != (-1, -1)]
        for c in candidates:
            x, y = c
            new_s = x + y
            if new_s < s:
                a, b, s = x, y, new_s

sys.stdout.write(f"{a} {b}\n")
