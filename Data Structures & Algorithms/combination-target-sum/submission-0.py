from collections import Counter

class Solution:

    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        def deconstruct_counters(c: frozenset):
            buf = []
            for key, value in c:
                for _ in range(value):
                    buf.append(key)
            return buf




        counts = set()

        def dfs(acc :int, c: Counter):
            if (acc > target): return
            if (acc == target): counts.add(frozenset(c.items()))

            print(c, counts)

            for num in nums: 
                c_copy = c.copy()
                c_copy[num] += 1
                dfs(acc + num, c_copy)
        
        dfs(0, Counter())

        return [deconstruct_counters(fs) for fs in counts]

                










            
        
            
