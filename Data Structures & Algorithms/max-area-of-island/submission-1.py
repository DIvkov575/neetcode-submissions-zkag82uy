# from collections im

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        max_area = 0
        visited = set()

        dx = [1,-1,0,0]
        dy = [0,0,-1, 1]
        def bfs(root):
            queue = [root]
            visited.add(root)
            area = 1 

            while len(queue) > 0:
                cur = queue.pop(0)

                for i in range(4):
                    ny = cur[0] + dx[i]
                    nx = cur[1] + dy[i]

                    if nx <0 or nx >= n or ny < 0 or ny >= m: continue

                    if grid[ny][nx] == 1 and (ny,nx) not in visited:
                        area += 1
                        visited.add((ny,nx))
                        queue.append((ny,nx))
            return area



        for i in range(m):
            for j in range(n): 
                if grid[i][j] == 1 and (i,j) not in visited:
                    area = bfs((i,j))
                    max_area = max(max_area, area)

        return max_area
            