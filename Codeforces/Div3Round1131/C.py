import sys

data = sys.stdin.buffer.read().split()
t = int(data[0])
index = 1
while t > 0:
    t -= 1
    n = int(data[index])
    a = list(map(int, data[index + 1 : index + 1 + n]))
    index += n + 1
    ans = 0
    if all(x == 1 for x in a):
        ans = -1
    else:
        check = False
        for i in range(1, n - 1):
            if a[i] > 1:
                check = True
                break
        if check:
            ans = sum(a) - 1
        else:
            ans = a[0] + a[n - 1] - 1
    sys.stdout.write(f"{ans}\n")
