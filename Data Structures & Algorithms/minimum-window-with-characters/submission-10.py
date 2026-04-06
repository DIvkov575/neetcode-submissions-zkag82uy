from collections import Counter, defaultdict

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t:
            return ""
        
        t_count = Counter(t)
        count = defaultdict(int)
        l = 0
        have = 0
        res = ""
        
        for r in range(len(s)):
            ch = s[r]
            count[ch] += 1
            
            if ch in t_count and count[ch] == t_count[ch]:
                have += 1
            
            while have == len(t_count):
                if not res or (r - l + 1) < len(res):
                    res = s[l:r+1]
                
                remove = s[l]
                if remove in t_count and count[remove] == t_count[remove]:
                    have -= 1
                count[remove] -= 1
                l += 1
        
        return res