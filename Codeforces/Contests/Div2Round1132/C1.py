import sys, math


def get_primes(n: int) -> list[int]:
    is_prime = [True] * (n + 1)
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2, n + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    primes = [i for i in range(n + 1) if is_prime[i]]
    return primes


data = sys.stdin.buffer.read().split()
t = int(data[0])
index = 1
primes = get_primes(2 * 10**5)
print(len(primes))

while t > 0:
    t -= 1
    n = int(data[index])
    a = list(map(int, data[index + 1 : index + 1 + n]))
    index += n + 1
    ans = []
    for v in a:
        l, r, pos = 0, len(primes), -1
        while l <= r:
            m = (l + r) >> 1
            if primes[m] < v:
                l = m + 1
            else:
                pos = m
                r = m - 1
        if pos != -1:
            ans.append(primes[pos])
    sys.stdout.write(" ".join(map(str, ans)) + "\n")
