from collections import Counter

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t:
            return ""

        min_len = float("inf")
        min_range = (0, 0)

        countt = Counter(t)
        counts = Counter()

        l = 0
        for r in range(len(s)):
            rs = s[r]
            counts[rs] += 1

            while l <= r and counts[s[l]] > countt[s[l]]:
                counts[s[l]] -= 1
                l += 1

            if all(counts[c] >= countt[c] for c in countt):
                if (r - l + 1) < min_len:
                    min_len = r - l + 1
                    min_range = (l, r)

        l, r = min_range
        return "" if min_len == float("inf") else s[l:r+1]