from functools import cache
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:

        @cache
        def dp(x,y):
            if x == 0 and y == 0:
                return 1
            elif x == 0:
                return dp(x,y-1)
            elif y == 0:
                return dp(x-1,y)
            else:
                return dp(x-1, y) + dp(x,y-1)

        return dp(m-1,n-1)



        