class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        m = len(grid[0])

        ctr = 0
        visited = set()

        repeated = -1
        dne = -1
        
        for i in range(n):
            for j in range(m):
                x = grid[i][j]
                if x in visited:
                    repeated = x
                else:
                    visited.add(x)
                    ctr += x
        
        dne = int((n**2)*(n**2+1)/2 - ctr)

        return [repeated, dne]


        
        