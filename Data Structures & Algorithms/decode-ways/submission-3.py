class Solution:
    def numDecodings(self, s: str) -> int:
        if len(s) == 1 and s[0] == "0":
            return 0
        elif len(s) == 1:
            return 1

        n = len(s)
        dp = [0 for _ in range(n)]

        if s[0] != "0": dp[0] = 1

        if s[1] != "0": dp[1] += dp[0]
        if (s[0] == "1") or (s[0] == "2" and s[1] in ["0", "1", "2", "3", "4", "5", "6"]): dp[1] += 1

        for i in range(2, n):
            if s[i] != "0": dp[i] += dp[i - 1]

            if (s[i-1] == "1") or (s[i-1] == "2" and s[i] in ["0", "1", "2", "3", "4", "5", "6"]): dp[i] += dp[i-2]
        
        return dp[n-1]


        