from collections import defaultdict
# def key(char: str) -> int:
    # return int(ord(char) - ord('a'))

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == "": return 0

        max_len = 1
        counts = defaultdict(int)
        counts[s[0]] += 1

        l = 0
        for r in range(1, len(s)):
            counts[s[r]] += 1

            # if s[r] > 1:
            while counts[s[r]] > 1:
                counts[s[l]] -= 1
                l += 1

            max_len = max(max_len, r-l+1)
        
        return max_len


        
        

        