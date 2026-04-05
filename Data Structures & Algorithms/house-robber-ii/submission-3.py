from copy import deepcopy
class Solution:
    def rob(self, nums: List[int]) -> int:
        sum_best = 0
        for rot in range(len(nums)):
            nums2 = deepcopy(nums)
            for i in range(2, len(nums)-1):
                mx = max(nums2[(rot+j)%len(nums)] for j in range(i-1))
                nums2[(rot+i)%len(nums)] += mx
            
            sum_best = max(sum_best, max(nums2))

        return sum_best

        