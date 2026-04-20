class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum%2 == 1) {return false;}
        vector<bool> dp(sum + 1, false);
        dp[0] = true;

        for (int num: nums) {
            for (int i = sum / 2 + 1; i >= 0; --i) {
                if (dp[i]) {
                    dp[i + num] = true;
                    if (i + num == sum / 2)  {
                        return true;
                    }
                }
            }
            dp[num] = true;
        }

        return false;
    }
};
