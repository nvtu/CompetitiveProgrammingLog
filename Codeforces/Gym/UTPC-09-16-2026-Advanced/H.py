n = int(input())
digits = input()[::-1]

ans = []
carry = 0
suf = [0] * (n + 1)
for i in range(n - 1, -1, -1):
    suf[i] = suf[i + 1] + int(digits[i])

for i in range(n):
    v = suf[i] + carry
    ans.append(v % 10)
    carry = v // 10

while carry:
    ans.append(carry % 10)
    carry //= 10

while len(ans) > 0 and ans[-1] == 0:
    ans.pop()

print("".join(map(str, reversed(ans))))
