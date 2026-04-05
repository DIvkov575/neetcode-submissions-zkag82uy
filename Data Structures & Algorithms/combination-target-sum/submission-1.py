from collections import Counter

class Solution:

    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        unq = []

        def dfs(acc:int, path: List[int], idx:int):
            if (acc == target):
                unq.append(path.copy())
                return
            if (idx>=len(nums)) or (acc > target):
                return

            path.append(nums[idx])
            dfs(acc + nums[idx], path, idx)
            path.pop()
            dfs(acc, path, idx+1)


        dfs(0, [], 0)

        return unq




            
