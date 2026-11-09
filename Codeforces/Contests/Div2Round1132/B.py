import sys

data = sys.stdin.buffer.read().split()
t = int(data[0])
index = 1
while t > 0:
    t -= 1
    n, k = map(int, data[index : index + 2])
    a = sorted(list(map(int, data[index + 2 : index + 2 + n])))
    index += n + 2
    b = a[n - k :]
    r = a[: n - k]

    ans = [*b, *r[::-1]]
    ok = True
    s = ans[0]
    k -= 1
    for i in range(1, n):
        if ans[i] * i >= s:
            k -= 1
        s += ans[i]

    if k != 0:
        sys.stdout.write("NO\n")
    else:
        sys.stdout.write("YES\n")
        sys.stdout.write(" ".join(map(str, ans)) + "\n")
