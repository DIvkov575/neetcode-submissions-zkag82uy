class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        # mindx = min(list(range(len(strs))), key=lambda x: len(strs[x]))
        prefix = strs[0]

        for string in strs:
            n = min(len(prefix), len(string))
            for i in range(n):
                if prefix[i] != string[i]:
                    n = i
                    break
            prefix= prefix[0:n]
        
        return prefix
        