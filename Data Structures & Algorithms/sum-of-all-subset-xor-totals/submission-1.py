class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        acc = 0

        buf = 0
        def dfs(idx):
            nonlocal buf, acc
            if idx >= len(nums):
                return
            
            buf ^= nums[idx]
            acc += buf

            dfs(idx+1)

            buf ^= nums[idx]
            dfs(idx+1)

            

        dfs(0)
        return acc

        