# class Solution:
#     def reverse(self, x: int) -> int:
#         neg = (x < 0)
#         out = 0

#         MAX = 2**31 - 1

#         while x!=0 and x <= 2**31 - 1:
#             out *= 10
#             out += x%10
#             x //= 10
        
#         if x > 2**31 - 1:
#             return 0

#         if neg: return -out
#         else: return out


class Solution:
    def reverse(self, x: int) -> int:
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        rev = 0

        while x != 0:
            digit = int(x % 10)

            if x < 0 and digit > 0:
                digit -= 10

            x = (x - digit) // 10

            if rev > INT_MAX // 10 or rev < INT_MIN // 10:
                return 0

            if rev == INT_MAX // 10 and digit > 7:
                return 0

            if rev == INT_MIN // 10 and digit < -8:
                return 0

            rev = rev * 10 + digit

        return rev 