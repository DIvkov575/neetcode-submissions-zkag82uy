class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        mapping = {
            "2": ['a', 'b', 'c'],
            "3": ['d', 'e', 'f'],
            "4": ['g', 'h', 'i'],
            "5": ['j', 'k', 'l'],
            "6": ['m', 'n', 'o'],
            "7": ['p', 'q', 'r', 's'],
            "8": ['t', 'u', 'v'],
            "9": ['w', 'x', 'y', 'z']
        }

        outputs = []
        buf = []
        def dfs(idx):
            if idx == len(digits): 
                if buf: outputs.append("".join(buf))
                return
            
            if digits[idx] in mapping.keys():
                for char in mapping[digits[idx]]:
                    buf.append(char)
                    dfs(idx+1)
                    buf.pop()
            else:
                dfs(idx+1)
            
        
        dfs(0)
        return outputs


            
            
        