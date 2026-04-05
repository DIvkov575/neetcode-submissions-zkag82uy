class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        rec = 0
        for num in nums:
            key = 1 << num
            if rec & key != 0:
                return num
            else:
                rec ^= key
            
        