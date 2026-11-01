import sys

data = sys.stdin.buffer.read().split()
n = int(data[0])
s = data[1].decode("utf-8")

L = [i + 1 for i in range(n) if s[i] == "L"]
R = [i + 1 for i in range(n) if s[i] == "R"]


def upper_bound(val: int, l: int, r: int, arr: list[int]) -> int:
    ans = -1
    while l <= r:
        m = (l + r) >> 1
        if arr[m] <= val:
            l = m + 1
        else:
            ans = m
            r = m - 1
    return ans


ans = 0
cvLl, cvLr, cvRl, cvRr = len(R), len(R), len(L), len(L)
for i in range(2 * n + 1):
    nL, nR = cvLr - cvLl + cvRl, cvRr - cvRl + cvLl

    flip_pos_for_L, flip_pos_for_R = upper_bound(nL, 0, cvRl - 1, L), upper_bound(
        nR, 0, cvLl - 1, R
    )

    remove_pos_for_L, remove_pos_for_R = upper_bound(
        nL, cvLl, cvLr - 1, R
    ), upper_bound(nR, cvRl, cvRr - 1, L)

    if flip_pos_for_L != -1:
        cvRl = flip_pos_for_L
    if remove_pos_for_L != -1:
        cvLr = remove_pos_for_L
    if flip_pos_for_R != -1:
        cvLl = flip_pos_for_R
    if remove_pos_for_R != -1:
        cvRr = remove_pos_for_R

    if (
        flip_pos_for_L == -1
        and flip_pos_for_R == -1
        and remove_pos_for_L == -1
        and remove_pos_for_R == -1
    ):
        ans = nL + nR
        break

sys.stdout.write(f"{ans}\n")
