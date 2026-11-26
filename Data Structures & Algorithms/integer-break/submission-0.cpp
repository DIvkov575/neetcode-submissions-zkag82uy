class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        for (int i = 1; i < n; ++i) {
            dp[i] = i;
        }
        for (int i = 1; i < n; ++i)  {
            for (int j = 1; j <= n-i; ++j) {
                dp[i+j] = max(dp[i+j], dp[i]*j);
            }
        }

        return dp[n];
        
    }
};