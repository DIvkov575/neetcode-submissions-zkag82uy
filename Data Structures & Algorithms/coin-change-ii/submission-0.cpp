class Solution {
    vector<vector<int>> dp;

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        dp.assign(amount + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= n; ++i) {
            dp[0][i] = 1;
        }

        for (int t = 1; t <= amount; ++t) {
            for (int i = n - 1; i >= 0; --i) {

                dp[t][i] = dp[t][i + 1];

                if (t >= coins[i]) {
                    dp[t][i] += dp[t - coins[i]][i];
                }
            }
        }

        return dp[amount][0];
    }
};