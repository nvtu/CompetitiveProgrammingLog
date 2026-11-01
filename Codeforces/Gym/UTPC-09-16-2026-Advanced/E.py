import sys

data = sys.stdin.buffer.read().split()
n, k = map(int, data[:2])
s = [int(c) for c in data[2].decode("utf-8")]

prefix_sum = [0] * n
prefix_sum[0] = s[0]
for i in range(1, n):
    prefix_sum[i] = prefix_sum[i - 1] + s[i]

suffix_max = [0] * (n + 1)
count_one = 0

for i in range(n - 1, n - 1 - k, -1):
    count_one += s[i]
    suffix_max[i] = max(suffix_max[i + 1], count_one)

for i in range(n - 1 - k, -1, -1):
    count_one = count_one + s[i] - s[i + k]
    suffix_max[i] = max(suffix_max[i + 1], count_one)

ans = prefix_sum[k - 1] + suffix_max[k]
for i in range(k, n):
    ans = max(ans, prefix_sum[i] - prefix_sum[i - k] + suffix_max[i + 1])

sys.stdout.write(f"{ans}\n")
