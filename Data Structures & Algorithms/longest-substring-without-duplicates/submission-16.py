class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = 0
        h = 0
        max_len = 0

        while l < len(s):
            h = l
            unique_characters = set()

            if (l < len(s)):
                unique_characters |= {s[l]}

            # increment rp
            while (h < len(s) - 1) and (s[h+1] not in unique_characters):
                unique_characters |= {s[h+1]}
                h += 1 

            max_len = max(max_len, len(unique_characters))

            # increment lp
            l -= 1
            while (l < len(s) - 1) and (h < len(s) - 1) and (s[l+1] != s[h+1]):
                l += 1
            l+=2

        return max_len