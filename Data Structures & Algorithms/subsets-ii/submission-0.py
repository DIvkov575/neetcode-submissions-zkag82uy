from copy import deepcopy
from collections import Counter
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        counts = Counter(nums)
        # keys = list(counts.key()) + [100]
        keys = list(counts.keys())
        output = []

        buf =[]
        def dfs(idx):
            if idx == len(keys):
                output.append(deepcopy(buf))
                # while buf[-1] == keys[idx]:
                #    buf.pop() 
                return

            dfs(idx+1)
            for i in range(counts[keys[idx]]):
                buf.append(keys[idx])
                dfs(idx+1)

            while buf and buf[-1] == keys[idx]:
                buf.pop() 
            


        dfs(0)
        return output

        