class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        buf = []
        output = []
    
        def dfs(nlplaced, nrplaced):
            print(buf, nlplaced, nrplaced)
            if nlplaced == n:
                output.append("".join(buf) + (n-nrplaced)* ")")
                return

            buf.append("(")
            dfs(nlplaced + 1, nrplaced)
            buf.pop()
    
            if nlplaced > nrplaced:
                buf.append(")")
                dfs(nlplaced, nrplaced+1)
                buf.pop()

    
        dfs(0, 0)
        return output
    
        
        