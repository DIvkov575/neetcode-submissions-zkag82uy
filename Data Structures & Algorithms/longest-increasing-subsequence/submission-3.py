from typing import List

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = []

        for num in nums:
            l,r = 0, len(dp)

            while l < r:
                m = (r+l)//2

                if dp[m] < num:
                    l = m+1
                else:
                    r = m
            
            if l == len(dp):
                dp.append(num)
            else:
                dp[l] = num

        return len(dp)
