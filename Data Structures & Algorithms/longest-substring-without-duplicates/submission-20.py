class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = 0
        h = 0
        max_len = 0

        uchars = {}

        while h < len(s):
            prev_pos = uchars.get(s[h], -1)


            if prev_pos == -1 or prev_pos < l: # seen beforej
                max_len = max(max_len, h - l + 1)
            else:
                l = prev_pos + 1

            uchars[s[h]] = h
            h += 1

            # max_len = max(max_len, h - l)




        return max_len