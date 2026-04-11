class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def save_sol(solutions, board):
            solutions.append([])
            for row in board:
                solutions[-1].append("".join(row))

        board = [["." for _ in range(n)] for _ in range(n)]
        solutions = []


        qc = set()
        qd = set()
        qa = set()

        def dfs(r):
            if r >= n:
                save_sol(solutions, board)
            
            for c in range(n):
                if c not in qc and r - c not in qd and c + r not in qa:
                    qc.add(c)
                    qd.add(r-c)
                    qa.add(c+r)

                    board[r][c] = "Q"

                    dfs(r+1)

                    board[r][c] = "."

                    qc.remove(c)
                    qd.remove(r-c)
                    qa.remove(c+r)
        
        dfs(0)
        return solutions




            






        dfs(0)
        return solutions

        