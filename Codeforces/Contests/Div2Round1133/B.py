import sys

t = int(input())
while t > 0:
    t -= 1
    n = int(input())
    sys.stdout.write(f"? 1 {n}\n")
    sys.stdout.flush()

    total = int(input())
    ans = "NO"
    if 0 < total < n:
        sys.stdout.write(f"? 1 {total}\n")
        sys.stdout.flush()
        inp = int(input())
        if inp < total:
            ans = "YES"

    sys.stdout.write(f"! {ans}\n")
    sys.stdout.flush()
