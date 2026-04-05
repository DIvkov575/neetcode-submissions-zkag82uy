class Solution:
    def reverseBits(self, n: int) -> int:
        out = 0
        for i in range(32):
            out |= (((n >> i)& 1 ) << (31-i))
            # if ((n >> i) & 1):
            #     out |= (1 << (31 - i))


        return out
            
        