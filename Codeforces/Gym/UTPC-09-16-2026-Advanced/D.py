import sys
import math

data = sys.stdin.buffer.read().split()
n, t = map(int, data[:2])
a = list(map(int, data[2:]))

C, S = 0, 0

for i in range(n):
    lcm = 1
    for j in range(i, n):
        lcm = math.lcm(lcm, a[j])
        if lcm <= t:
            C += 1
            S += j - i + 1
        else:
            break

sys.stdout.write(f"{C} {S}\n")