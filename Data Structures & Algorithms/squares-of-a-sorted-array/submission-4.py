class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        nums = [elem**2 for elem in nums]
        n = len(nums)
        res = [0]*n

        l = 0
        r = n-1
        m = n-1

        while l <= r:
            if nums[l] < nums[r]:
                res[m] = nums[r]
                r -= 1
                m -= 1
            else:
                res[m] = nums[l]
                l += 1
                m -= 1
        
        return res




        