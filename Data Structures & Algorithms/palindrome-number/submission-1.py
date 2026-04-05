class Solution:
    def isPalindrome(self, x: int) -> bool:
        num = []
        if x < 0: return False

        while x!=0:
            num.append(x%10)
            x //= 10
       
        for i in range(len(num)//2):
            if num[i] != num[len(num)-i-1]:
                return False
        return True
