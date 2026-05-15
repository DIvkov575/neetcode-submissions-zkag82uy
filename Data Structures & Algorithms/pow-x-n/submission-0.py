class Solution:
    def myPow(self, x: float, n: int) -> float:

        def dfs(n):
            if n < 0:
                return 1/dfs(-n)
            elif n == 0:
                return 1
            elif (n%2== 1):
                return x * dfs(n//2) * dfs(n//2)
            else:
                return dfs(n//2) * dfs(n//2)

        return dfs(n)
        