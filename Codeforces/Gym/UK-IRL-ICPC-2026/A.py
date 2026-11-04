from collections import Counter
import sys

data = sys.stdin.buffer.read().split()
n, k = map(int, data[:2])
s = []
for i in range(n):
    letters = data[i + 2].decode("utf-8")
    s.append(letters)

count = Counter("".join(s))
most_commons = count.most_common(k)
cs = [v[0] for v in most_commons]

ans = []

for i in range(n):
    new_s = ""
    for j in range(len(s[i])):
        if s[i][j] not in cs:
            new_s += cs[0]
        else:
            new_s += s[i][j]
    ans.append(new_s)

sys.stdout.write(" ".join(ans) + "\n")
