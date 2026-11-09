import sys, math
from dataclasses import dataclass
from functools import cmp_to_key


@dataclass
class Point:
    x: int
    y: int


def cross(A: Point, B: Point, C: Point) -> int:
    return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y)


def ccw(A: Point, B: Point, C: Point) -> int:
    S = cross(A, B, C)
    if S < 0:
        return -1
    if S == 0:
        return 0
    return 1


def convex_hull(p: list[Point], n: int) -> list[Point]:
    def compare(A, B):
        c = ccw(p[0], A, B)
        if c > 0:
            return -1
        if c < 0:
            return 1

        # Tie-breaker: sort by x, then by y
        if A.x != B.x:
            return -1 if A.x < B.x else 1
        if A.y != B.y:
            return -1 if A.y < B.y else 1
        return 0

    for i in range(1, n):
        if p[0].y > p[i].y or (p[0].y == p[i].y and p[0].x > p[i].x):
            p[0], p[i] = p[i], p[0]

    p[1:] = sorted(p[1:], key=cmp_to_key(compare))
    hull = [p[0]]
    for i in range(1, n):
        while len(hull) >= 2 and ccw(hull[-2], hull[-1], p[i]) < 0:
            hull.pop()
        hull.append(p[i])
    return hull


def distance(A: Point, B: Point) -> float:
    return math.sqrt((A.x - B.x) ** 2 + (A.y - B.y) ** 2)


data = sys.stdin.buffer.read().split()
n, m = map(int, data[:2])
p = [Point(x=int(data[i]), y=int(data[i + 1])) for i in range(2, (n + 1) << 1, 2)]

cp = convex_hull(p, n)

y, x = 10**6, 0
pos = 0
for i in range(len(cp)):
    if cp[i].y < y:
        pos = i
        x, y = cp[i].x, cp[i].y
    elif cp[i].y == y and cp[i].x > x:
        pos = i
        x, y = cp[i].x, cp[i].y
m -= cp[pos].x

lens = [
    *[distance(cp[i], cp[i - 1]) for i in range(pos + 1, len(cp))],
    distance(cp[-1], cp[0]),
    *[distance(cp[i], cp[i - 1]) for i in range(1, pos + 1)],
]
total_lens = sum(lens)
ans = int(math.floor(m / total_lens + 1e-9)) + 1
sys.stdout.write(f"{ans}\n")
