n, m = map(int, input().split())
grid = [input() for _ in range(n)]

dx, dy = [0, 0, -1, 1], [1, -1, 0, 0]

ans = 0
for i in range(1, n - 1):
    for j in range(1, m - 1):
        if grid[i][j] == ".":
            all_good = True
            for k in range(4):
                nx, ny = i + dx[k], j + dy[k]
                if not (0 <= nx < n and 0 <= ny < m and grid[nx][ny] == "."):
                    all_good = False
                    break
            if all_good:
                ans += 1
print(ans)
