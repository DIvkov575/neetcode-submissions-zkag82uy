class Solution:
    def reverse(self, x: int) -> int:
        MAX = (2**31 - 1) // 10 -9 # peep the -9 does htis prevent overflow?
        neg = (x < 0)

        out = 0
        x = abs(x)

        while x!=0:
            if out > MAX: return 0

            out *= 10
            out += x%10
            x //= 10
        
        if neg: return -out
        else: return out


