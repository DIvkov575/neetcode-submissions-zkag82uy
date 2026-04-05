class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:

        def foo(nums):
            if len(nums) == 1:
                return [nums] + [[]]
            # if len(nums == 0):
            #     raise "unreachable"
            #     # return [[]]

            tmp = foo(nums[1:])  
            tmp2 = [[nums[0]] + elem for elem in tmp]

            return tmp + tmp2

        return foo(nums)