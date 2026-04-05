from typing import List

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        tails = []

        for x in nums:
            l, r = 0, len(tails)

            while l < r:
                m = (l + r) // 2
                if tails[m] < x:
                    l = m + 1
                else:
                    r = m

            if l == len(tails):
                tails.append(x)
            else:
                tails[l] = x

        return len(tails)
        