class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x

        l, r = 0, x // 2
        best = 0

        while l <= r:
            m = l + (r - l) // 2
            sq = m * m

            if sq == x:
                return m
            elif sq < x:
                best = m
                l = m + 1
            else:
                r = m - 1

        return best