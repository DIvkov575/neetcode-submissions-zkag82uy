import copy

class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        if target == 0: return [[]]

        output = []

        def combo(buf: List[int], sm: int, idx: int):
            nonlocal output

            if sm > target or idx >= len(nums): return
            elif sm == target: 
                output.append(copy.deepcopy(buf))
                return


            buf.append(nums[idx])
            combo(buf, sm+nums[idx], idx)

            buf.pop()
            # sm -= nums[idx]
            combo(buf, sm, idx+1)



        combo([],0, 0)
        return output
        
