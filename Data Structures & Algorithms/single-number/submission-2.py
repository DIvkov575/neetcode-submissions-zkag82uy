class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ledger = 0

        for num in nums:
            ledger ^= (1<<(num+1000))

        return ledger.bit_length()-1-1000
        