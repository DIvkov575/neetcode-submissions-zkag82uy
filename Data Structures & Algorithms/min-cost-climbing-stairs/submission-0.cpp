class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // if (n == 3) { return min(cost[0], cost[1]); }

        vector<int> dp(cost.size() + 2);
        dp[0] = 0;
        dp[1] = 0;


        for (int i =0; i < n; ++i) {
            dp[i + 2] = dp[i] + cost[i];

            if (dp[i] + cost[i] < dp[i+1]) {
                dp[i+1] = dp[i] + cost[i];
            }
        }

        
        // if (dp[n-2] + cost[n-2] < dp[n-1]) {
        //     dp[n-1] = dp[n-2] + cost[n-2];
        // }

        return min(dp[n], dp[n+1]);

        
    }
};
