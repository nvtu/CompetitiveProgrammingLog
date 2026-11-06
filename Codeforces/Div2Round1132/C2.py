import sys, math

data = sys.stdin.buffer.read().split()
index = 1
t = int(data[0])
while t > 0:
    t -= 1
    a, b = map(int, data[index : index + 2])
    index += 2

    if a == b:
        sys.stdout.write("0\n")
    else:
        trace = []
        diff = b - a
        if math.gcd(a, b) == 1:
            trace.append(diff)
        else:
            for i in range(1, min(100, diff)):
                if math.gcd(a, i) == 1 and math.gcd(a + i, b) == 1:
                    trace.append(i)
                    trace.append(diff - i)
                    break

            if len(trace) == 0:
                for i in range(1, min(100, diff)):
                    for j in range(1, min(100, diff - i)):
                        if (
                            math.gcd(a, i) == 1
                            and math.gcd(a + i, j) == 1
                            and math.gcd(a + i + j, b) == 1
                        ):
                            trace.append(i)
                            trace.append(j)
                            trace.append(diff - i - j)
                            break
                    if len(trace) > 0:
                        break

        sys.stdout.write(f"{len(trace)}\n")
        sys.stdout.write(" ".join(map(str, trace)) + "\n")
