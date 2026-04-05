class Solution:
    def reverse(self, x: int) -> int:
        neg = (x < 0)
        out = 0

        # MAX = 2**31 - 1

        x = abs(x)
        while x!=0 and out <= 2**31 - 1:
            out *= 10
            out += x%10
            x //= 10
        
        if out > 2**31 - 1:
            return 0

        if neg: return -out
        else: return out


