class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        n = len(nums)

        out = [-1 for _ in range(n*2)]
        for i in range(n):
            out[i] = out[i+n] = nums[i]
        return out

        # out = []
        # for i in range(n):
        #     out.append(nums[i])
        # for i in range(n):
        #     out.append(nums[i])