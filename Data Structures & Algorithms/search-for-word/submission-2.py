from copy import deepcopy

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        n = len(board)
        m = len(board[0])

        directions = [(1,0), (0,1), (-1,0), (0,-1)]

        def dfs(widx: int, idx: tuple[int,int], visited: set[type[int,int]]):
            if widx >= len(word):
                return True
            
            y = idx[0]
            x = idx[1]

            if idx in visited: return False
            if not 0 <= x < m or not 0 <= y < n: return False
            if word[widx] != board[y][x]: return False

            visited.add(idx)
            for (dy, dx) in directions:
                if dfs(widx+1, (y + dy, x + dx), deepcopy(visited)): return True

            return False
            



        for i in range(len(board)):
            for j in range(len(board[0])):
                if dfs(0, (i,j), set()): return True
        
        return False



        