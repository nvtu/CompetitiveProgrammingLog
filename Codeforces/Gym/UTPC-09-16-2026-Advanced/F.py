import sys

data = sys.stdin.buffer.read().decode("utf-8").strip()
sum_digits = sum(list(map(int, data)))

while sum_digits > 9:
    temp = 0
    while sum_digits > 0:
        sum_digits, last_digits = divmod(sum_digits, 10)
        temp += last_digits
    sum_digits = temp

sys.stdout.write(f"{sum_digits}\n")
