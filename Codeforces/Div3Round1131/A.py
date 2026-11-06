import sys
from collections import Counter

data = sys.stdin.buffer.read().split()

t = int(data[0])
index = 1
while t > 0:
    t -= 1
    n, m = map(int, data[index : index + 2])
    p = data[index + 2].decode("utf-8")
    q = data[index + 3].decode("utf-8")
    index += 4
    ans = "YES"
    p_count, q_count = Counter(p), Counter(q)
    for qc, count in q_count.items():
        p_count[qc] = p_count.get(qc, 0) - count
    for c, count in p_count.items():
        if count < 0:
            ans = "NO"
            break
        elif count > 0:
            if c not in ["s", "i", "x"]:
                ans = "NO"
                break
    if p_count["s"] != 1 or p_count["i"] != 1 or p_count["x"] != 1:
        ans = "NO"
    sys.stdout.write(ans + "\n")
