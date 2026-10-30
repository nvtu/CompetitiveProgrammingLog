import sys
import math


class SegmentTree:
    def __init__(self, n: int, a: list[int]):
        self.n = n
        self._tree = [1] * (2 * self.n)
        for i in range(self.n):
            self._tree[self.n + i] = a[i]

    def build(self, limit: int):
        for i in range(self.n - 1, 0, -1):
            self._tree[i] = min(
                math.lcm(self._tree[i << 1], self._tree[i << 1 | 1]), limit + 1
            )

    def query(self, l: int, r: int, limit: int):
        ans = 1
        l += self.n
        r += self.n
        while l < r:
            if l & 1:
                ans = min(math.lcm(ans, self._tree[l]), limit + 1)
                l += 1
            if r & 1:
                r -= 1
                ans = min(math.lcm(ans, self._tree[r]), limit + 1)
            l >>= 1
            r >>= 1
        return ans


data = sys.stdin.buffer.read().split()
n, t = map(int, data[:2])
a = list(map(int, data[2:]))

C, S = 0, 0
st = SegmentTree(n, a)
st.build(t)

for i in range(n):
    if a[i] > t:
        continue
    l, r, pos = i, n - 1, i
    while l <= r:
        mid = (l + r) >> 1
        lcm = st.query(i, mid + 1, t)
        if lcm <= t:
            pos = mid
            l = mid + 1
        else:
            r = mid - 1

    length = pos - i + 1
    C += length
    S += (length * (length + 1)) >> 1

sys.stdout.write(f"{C} {S}\n")
