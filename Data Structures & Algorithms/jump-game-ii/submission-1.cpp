class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, numeric_limits<int>::max());
        dp[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 1; j <= min(nums[i], n-i-1); ++j) {
                dp[i+j] = min(dp[i+j], dp[i] +1);
            }
        }

        return dp[n-1];

        
    }
};
