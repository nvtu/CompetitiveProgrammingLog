import sys


def count_odd_even(x: list[int]) -> tuple[int, int]:
    evens, odds = 0, 0
    for i in range(len(x)):
        if x[i] & 1:
            odds += 1
        else:
            evens += 1
    return evens, odds


data = sys.stdin.buffer.read().split()
t = int(data[0])
index = 1
while t > 0:
    t -= 1
    n, k = map(int, data[index : index + 2])
    a = list(map(int, data[index + 2 : index + n + 2]))
    b = list(map(int, data[index + n + 2 : index + 2 * n + 2]))
    index += 2 * n + 2
    a_n_evens, a_n_odds = count_odd_even(a)
    b_n_evens, b_n_odds = count_odd_even(b)
    ans = "YES"
    if a_n_odds < b_n_odds:
        if (k & 1) == 0:
            ans = "NO"
    elif a_n_odds > b_n_odds:
        if k & 1:
            ans = "NO"

    sys.stdout.write(f"{ans}\n")
