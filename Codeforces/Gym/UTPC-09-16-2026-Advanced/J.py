import sys

data = sys.stdin.buffer.read().split()
n, q = map(int, data[:2])
a = list(map(int, data[2 : n + 1]))

MOD = 10**9 + 7


class SegmentTree:
    def __init__(self, n: int, arr: list[int]):
        self.n = n
        self._tree = [0] * (2 * self.n)
        self._lazy = [1] * self.n

        # Assign leaf nodes
        for i in range(self.n):
            self._tree[self.n + i] = arr[i]

        # # Build initial tree
        for i in range(self.n - 1, 0, -1):
            self._tree[i] = (self._tree[i << 1] + self._tree[i << 1 | 1]) % MOD

    def _build(self, p: int):
        while p > 1:
            p >>= 1
            self._tree[p] = (
                (self._tree[p << 1] + self._tree[p << 1 | 1]) * self._lazy[p] % MOD
            )

    def _apply(self, p: int, value: int):
        self._tree[p] = (self._tree[p] * value) % MOD
        if p < self.n:
            self._lazy[p] = (self._lazy[p] * value) % MOD

    def _push(self, p: int):
        h = self.n.bit_length()
        for s in range(h, 0, -1):
            i = p >> s
            if self._lazy[i] != 1:
                self._apply(i << 1, self._lazy[i])
                self._apply(i << 1 | 1, self._lazy[i])
                self._lazy[i] = 1

    def update(self, l: int, r: int, value: int):
        l += self.n
        r += self.n
        l0, r0 = l, r
        while l < r:
            if l & 1:
                self._apply(l, value)
                l += 1
            if r & 1:
                r -= 1
                self._apply(r, value)
            l >>= 1
            r >>= 1
        self._build(l0)
        self._build(r0 - 1)

    def query(self, l: int, r: int) -> int:
        l += self.n
        r += self.n
        self._push(l)
        self._push(r - 1)
        ans = 0
        while l < r:
            if l & 1:
                ans = (ans + self._tree[l]) % MOD
                l += 1
            if r & 1:
                r -= 1
                ans = (ans + self._tree[r]) % MOD
            l >>= 1
            r >>= 1
        return ans


w = [1] * (n - 1)
w[n - 2] = a[n - 2]
for i in range(n - 3, -1, -1):
    w[i] = (a[i] * w[i + 1]) % MOD

st = SegmentTree(n - 1, w)

ans = []
j = n + 1
for _ in range(q):
    c = int(data[j])
    j += 1
    if c == 1:
        i, x = map(int, data[j : j + 2])
        j += 2
        ratio = (x * pow(a[i - 1], MOD - 2, MOD)) % MOD
        a[i - 1] = x
        st.update(0, i, ratio)
    elif c == 2:
        i = int(data[j])
        j += 1
        w_i = st.query(i - 1, i) if i < n else 1
        S = (st.query(0, n - 1) + 1) % MOD
        if S % MOD == 0:
            ans.append(-1)
        else:
            ans.append((w_i * pow(S, MOD - 2, MOD)) % MOD)

sys.stdout.write("\n".join(map(str, ans)) + "\n")
