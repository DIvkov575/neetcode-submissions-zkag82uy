class Solution:
    def concatenatedBinary(self, n: int) -> int:
        acc = 0
        for i in range(1, n+1):
            acc = (acc << i.bit_length() | i)%(10**9+7)
        return acc
