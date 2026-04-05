from functools import cache


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)


        @cache
        def dp(idx):
            if idx == n-1:
                return True
            elif idx >= n:
                return False

            for i in range(nums[idx], 0, -1):
                if dp(idx+i): return True

            return False
        
        return dp(0)


        