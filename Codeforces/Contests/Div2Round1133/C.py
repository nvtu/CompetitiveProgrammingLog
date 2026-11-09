import sys


class SegmentTree:
    def __init__(self, n: int, a: list[int]):
        self.n = n
        self.tree = [0] * (n << 1)
        for i in range(self.n):
            self.tree[self.n + i] = a[i]
        for i in range(self.n - 1, 0, -1):
            self.tree[i] = max(self.tree[i << 1], self.tree[(i << 1) | 1])

    def query(self, l: int, r: int) -> int:
        l += self.n
        r += self.n
        ans = 0
        while l < r:
            if l & 1:
                ans = max(ans, self.tree[l])
                l += 1
            if r & 1:
                r -= 1
                ans = max(ans, self.tree[r])
            l >>= 1
            r >>= 1
        return ans


data = sys.stdin.buffer.read().split()
t = int(data[0])
index = 1

while t > 0:
    t -= 1
    n = int(data[index])
    a = list(map(int, data[index + 1 : index + n + 1]))
    index += n + 1
    pgaps = [abs(a[i] - a[i + 1]) for i in range(n - 1)]
    seg_tree, max_gap = (SegmentTree(n - 1, pgaps), max(pgaps))
    count, l, r = 0, -1, -1
    for i in range(n - 1):
        if pgaps[i] == max_gap:
            count += 1
            if l == -1:
                l = i
            else:
                r = i
    ans = max_gap
    if count == 1:
        # Case 1: r = i
        r = l
        for l in range(r + 1):
            gaps = [
                seg_tree.query(0, l - 1),
                abs((a[r] << 1) - a[l - 1]) if l > 0 else 0,
                seg_tree.query(l, r) << 1,
                abs((a[l] << 1) - a[r + 1]) if r + 1 < n else 0,
                seg_tree.query(r + 1, n - 1),
            ]
            ans = min(ans, max(gaps))

        # Case 2: l = i
        l = r + 1
        for r in range(l, n):
            gaps = [
                seg_tree.query(0, l - 1),
                abs((a[r] << 1) - a[l - 1]),
                seg_tree.query(l, r) << 1,
                abs((a[l] << 1) - a[r + 1]) if r + 1 < n else 0,
                seg_tree.query(r + 1, n - 1),
            ]
            ans = min(ans, max(gaps))
    elif count == 2:
        l += 1
        gaps = [
            seg_tree.query(0, l - 1),
            abs((a[r] << 1) - a[l - 1]),
            seg_tree.query(l, r) << 1,
            abs((a[l] << 1) - a[r + 1]) if r + 1 < n else 0,
            seg_tree.query(r + 1, n - 1),
        ]
        ans = min(ans, max(gaps))

    sys.stdout.write(f"{ans}\n")
