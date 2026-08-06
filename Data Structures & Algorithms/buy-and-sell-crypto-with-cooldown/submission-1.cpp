class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));

        if (n < 2) {
            return 0;
        } else if (n==2) {
            return max(prices[1]-prices[0], 0);
        }

        dp[0][0] = -prices[0];
        dp[0][1] = max(-prices[0], -prices[1]);
        dp[1][1] = max(dp[1][0], dp[0][0]+prices[1]);


        for (int i = 2; i < n; ++i) {
            dp[0][i] = max(dp[0][i-1], dp[1][i-2] - prices[i]); // B
            dp[1][i] = max(dp[1][i-1], dp[0][i-1] + prices[i]); // S
        }

        return max(dp[0][n-1], dp[1][n-1]);
    }
};