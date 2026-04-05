class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        mindx = min(list(range(len(strs))), key=lambda x: len(strs[x]))
        prefix = strs[mindx]

        for string in strs:
            for i in range(len(prefix)):
                if prefix[i] != string[i]:
                    prefix = prefix[0:i]
                    break
        
        return prefix
        