# sys.setrecursionlimit(3000)  

import copy
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        output = []
        
        def dfs(base, idx):
            nonlocal output
            
            if idx >= len(nums): return
            base.append(nums[idx])
            output.append(copy.deepcopy(base))
            dfs(base, idx+1)
            base.pop()
            dfs(base, idx+1)

        output.append([])
        dfs([], 0)
        return output
            
