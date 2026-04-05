class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        m: dict = {}

        for a,b in zip(s, t):
            if a in m:
                m[a] += 1
            else:
                m[a] = 1
            
            if b in m:
                m[b] -= 1
            else:
                m[b] = -1
        

        for value in m.values():
            if value != 0:
                return False
        return True