import sys


class Node:
    def __init__(self, id: int, parent: int, start_idx: int, end_idx: int):
        self._id = id
        self.parent = parent
        self.start_idx = start_idx
        self.end_idx = end_idx
        self.letter_count: int = 0
        self.children = []

    def __str__(self):
        return f"{self._id} {self.parent} {self.start_idx} {self.end_idx} {self.letter_count} {self.children}"


data = sys.stdin.buffer.read().split()
s = data[0].decode("utf-8")

total_letter = sum([1 if c.isalpha() else 0 for c in s])
if total_letter % 3:
    sys.stdout.write("impossible\n")
else:
    n = len(s)
    k = total_letter // 3
    tree, stk = [Node(0, -1, 0, n - 1)], [0]

    for i in range(n):
        if s[i] == "(":
            new_id = len(tree)
            tree.append(Node(new_id, stk[-1], i, -1))
            tree[stk[-1]].children.append(new_id)
            stk.append(new_id)
        elif s[i] == ")":
            cur = stk[-1]
            tree[cur].end_idx = i
            stk.pop()
        else:
            tree[stk[-1]].letter_count += 1

    m = len(tree)
    for i in range(m - 1, 0, -1):
        p = tree[i].parent
        tree[p].letter_count += tree[i].letter_count

    # for i in range(m):
    #     print(tree[i])

    found = False

    # Case 1: 2 subtrees that has size of K
    node1 = -1
    for i in range(m):
        if tree[i].letter_count == k:
            if node1 == -1 or tree[i].end_idx < tree[node1].end_idx:
                node1 = i
    if node1 != -1:
        node2 = -1
        for j in range(m):
            if tree[j].letter_count == k and tree[j].start_idx > tree[node1].end_idx:
                node2 = j
                break
        if node2 != -1:
            found = True
            line1 = (
                s[: tree[node1].start_idx]
                + "[1]"
                + s[tree[node1].end_idx + 1 : tree[node2].start_idx]
                + "[2]"
                + s[tree[node2].end_idx + 1 :]
            )
            line2 = "[1] " + s[tree[node1].start_idx + 1 : tree[node1].end_idx]
            line3 = "[2] " + s[tree[node2].start_idx + 1 : tree[node2].end_idx]
            sys.stdout.write(f"{line1}\n")
            sys.stdout.write(f"{line2}\n")
            sys.stdout.write(f"{line3}\n")

    if not found:
        candidates = [i for i in range(m) if tree[i].letter_count == k]
        for i in range(m):
            if found:
                break
            if tree[i].letter_count != (k << 1):
                continue
            l, r, p = 0, len(candidates) - 1, -1
            while l <= r:
                mid = (l + r) >> 1

                if tree[candidates[mid]].start_idx > tree[i].start_idx:
                    p = mid
                    r = mid - 1
                else:
                    l = mid + 1
            if p != -1 and tree[candidates[p]].start_idx < tree[i].end_idx:
                p = candidates[p]
                found = True
                line1 = s[: tree[i].start_idx] + "[1]" + s[tree[i].end_idx + 1 :]
                line2 = (
                    "[1] "
                    + s[tree[i].start_idx + 1 : tree[p].start_idx]
                    + "[2]"
                    + s[tree[p].end_idx + 1 : tree[i].end_idx]
                )
                line3 = "[2] " + s[tree[p].start_idx + 1 : tree[p].end_idx]
                sys.stdout.write(f"{line1}\n")
                sys.stdout.write(f"{line2}\n")
                sys.stdout.write(f"{line3}\n")

    if not found:
        sys.stdout.write("impossible\n")
