from collections import deque

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])

        ctr = 0        
        visited = set()

        def bfs(start):
            queue = [start]
            visited.add(start)

            dy = [1,0,-1,0]
            dx = [0,1,0,-1]

            while queue:
                cur = queue.pop(0)

                for i in range(4):
                    nr = cur[0] + dx[i]
                    nc = cur[1] + dy[i]

                    if nr < 0 or nr >= m or nc < 0 or nc >= n:
                        continue

                    if grid[nr][nc] == "1" and (nr, nc) not in visited:
                        visited.add((nr, nc))
                        queue.append((nr, nc))

        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1' and (i,j) not in visited:
                    bfs((i,j))
                    ctr += 1

        return ctr