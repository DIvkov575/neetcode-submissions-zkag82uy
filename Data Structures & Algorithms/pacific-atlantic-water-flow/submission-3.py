class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        n, m = len(heights), len(heights[0])
        dirs = [(1,0),(-1,0),(0,1),(0,-1)]

        pac = set()
        atl = set()

        def dfs(r, c, visited):
            visited.add((r, c))

            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if (
                    0 <= nr < n and
                    0 <= nc < m and
                    (nr, nc) not in visited and
                    heights[nr][nc] >= heights[r][c]
                ):
                    dfs(nr, nc, visited)

        for i in range(n):
            dfs(i, 0, pac)
            dfs(i, m - 1, atl)

        for j in range(m):
            dfs(0, j, pac)
            dfs(n - 1, j, atl)

        return [[r, c] for (r, c) in pac & atl]