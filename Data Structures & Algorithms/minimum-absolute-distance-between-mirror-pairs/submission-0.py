class Solution:
    def minMirrorPairDistance(self, nums: List[int]) -> int:
        mind = float("inf")
        rev_idxs = {}

        for (idx, num) in enumerate(nums):
            if num in rev_idxs:
                mind = min(mind, idx - rev_idxs[num])

            rev_idxs[int(str(num)[::-1])] = idx

        if mind == float("inf"):
            return -1
        
        return mind
