class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        for i in range(len(haystack)-len(needle)+1):
            state = True
            for j in range(len(needle)):
                if needle[j] != haystack[i+j]:
                    state = False
                    break
            if state: return i
        return -1
                    
            

                

        