import sys

data = sys.stdin.buffer.read().split()
s = data[0].decode("utf-8")
X, remains = s.split("+")
Y, Z = remains.split("=")
n = len(X)


def validate(X: str, Y: str, Z: str, ans: list[int]) -> bool:
    m = len(ans)
    for i in range(m):
        for j in range(i + 1, m):
            if ans[i] == ans[j]:
                return False
    n = len(X)
    carry = 0
    for i in range(n - 1, -1, -1):
        xc, yc, zc = ord(X[i]) - ord("a"), ord(Y[i]) - ord("a"), ord(Z[i]) - ord("a")
        x, y, z = ans[xc], ans[yc], ans[zc]
        carry, res_z = divmod(x + y + carry, 10)
        if res_z != z:
            return False
    if carry > 0:
        return False
    return True


def find_solutions(X: str, Y: str, Z: str) -> list[int]:
    for i in range(10):
        for j in range(10):
            for k in range(10):
                for t in range(10):
                    for u in range(10):
                        ans = [i, j, k, t, u]
                        if validate(X, Y, Z, ans):
                            return ans
    return [-1] * 5


ans = find_solutions(X, Y, Z)
if all(x == -1 for x in ans):
    sys.stdout.write("impossible\n")
else:
    sys.stdout.write("".join([str(d) for d in ans]) + "\n")
