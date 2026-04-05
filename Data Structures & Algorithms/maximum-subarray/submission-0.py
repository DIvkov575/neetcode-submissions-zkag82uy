class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        best = nums[0]
        

        acc = 0
        for i in range(len(nums)):
            acc += nums[i]

            best = max(best, acc)

            acc = max(acc, 0)

        return best
