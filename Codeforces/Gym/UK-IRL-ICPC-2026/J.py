import sys
from collections import deque

data = sys.stdin.buffer.read().split()
n, l = map(int, data[:2])
a = [0, *list(map(int, data[2:]))]
p = sorted(range(n + 1), key=a.__getitem__)

trace = [[-1] * (n + 1) for _ in range(l + 1)]
NEG_INF = float("-inf")


def is_redundant(
    l1: tuple[int, int, int], l2: tuple[int, int, int], l3: tuple[int, int, int]
) -> bool:
    m1, c1, _ = l1
    m2, c2, _ = l2
    m3, c3, _ = l3
    lhs = (c3 - c1) * (m1 - m2)
    rhs = (c2 - c1) * (m1 - m3)
    return lhs <= rhs


def add_line(dq: deque, m: int, c: int, j: int):
    if dq and dq[-1][0] == m:
        if dq[-1][1] >= c:
            return
        dq.pop()
    new_line = (m, c, j)
    while len(dq) >= 2 and is_redundant(dq[-2], dq[-1], new_line):
        dq.pop()
    dq.append(new_line)


def query(dq: deque, i: int) -> tuple[int, int]:
    while len(dq) >= 2 and (dq[0][0] * i + dq[0][1]) <= (dq[1][0] * i + dq[1][1]):
        dq.popleft()
    best_line = dq[0]
    return best_line[0] * i + best_line[1], best_line[2]


dp_prev = [NEG_INF] * (n + 1)
dp_prev[0] = 0

M = [0] * (n + 1)
C = [0] * (n + 1)
J = [0] * (n + 1)

for k in range(1, l + 1):
    dp_cur = [NEG_INF] * (n + 1)
    dq = deque()
    for i in range(1, n + 1):
        j = i - 1
        if dp_prev[j] != NEG_INF:
            add_line(dq, a[p[j + 1]], dp_prev[j] - a[p[j + 1]] * j, j)

        if dq:
            dp_cur[i], best_j = query(dq, i)
            trace[k][i] = best_j

    dp_prev = dp_cur


blocks = [0] * (n + 1)
i = n
for k in range(l, 0, -1):
    prev_j = trace[k][i]
    block_range = range(prev_j + 1, i + 1)
    for index in block_range:
        blocks[p[index]] = k
    i = prev_j

ans = dp_prev[n] / n
sys.stdout.write(f"{ans:.6f}\n")
sys.stdout.write(" ".join(map(str, blocks[1:])) + "\n")
