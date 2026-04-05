class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        ledger = 0
        for num in nums:
            ledger |= 1 << num

        
        ledger ^= 2**(len(nums)+1) - 1

        return ledger.bit_length() - 1
        