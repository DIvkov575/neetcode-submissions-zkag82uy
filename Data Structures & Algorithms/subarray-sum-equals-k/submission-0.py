class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        pres = [0 for _ in range(n)]
        pres[0] = nums[0]
        for i in range(1, n):
            pres[i] = pres[i-1] + nums[i]
        
        counts = {0: 1}
        # for pre in pres :
        #     if pre in counts:
        #         counts[pre] += 1
        #     else:
        #         counts[pre] = 1
        
        ctr = 0
        for prer in pres:
            prel = prer - k
            if prel in counts:
                ctr += counts[prel]
            
            if prer in counts:
                counts[prer] += 1
            else:
                counts[prer] = 1
        
        return ctr

        
        
        