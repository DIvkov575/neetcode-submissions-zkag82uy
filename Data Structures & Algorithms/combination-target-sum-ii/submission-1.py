from copy import deepcopy

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        outputs = []

        buf = []
        def search(buf, sm, idx):
            nonlocal outputs
            if sm > target or idx >= len(candidates): return

            buf.append(candidates[idx])
            if sm+candidates[idx] == target:
                outputs.append(deepcopy(buf))
            elif sm+candidates[idx] < target:
                search(buf, sm+candidates[idx], idx+1)
            
            buf.pop()
            while idx < len(candidates) - 1 and candidates[idx] == candidates[idx + 1]: idx += 1
            search(buf, sm, idx + 1)
        
        search(buf, 0, 0)
        return outputs
        