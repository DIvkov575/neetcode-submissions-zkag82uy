class Solution {
public:
    struct PairHash {
        size_t operator()(const std::pair<int,int>& p) const {
            uint64_t combined =
                ((uint64_t)p.first << 32) | (uint32_t)p.second;
    
            return std::hash<uint64_t>{}(combined);
        }
    };


    vector<int> nums;
    int target;

    unordered_map<pair<int, int>, int, PairHash> dp;



    // dfs outputs the number of ways to achieve a certain value given some number of indices

    int dfs(int idx, int sum) {
        auto it = dp.find({idx, sum});
        if (it == dp.end()) {
            if (idx == -1 && sum == target)  {
                dp[{idx, sum}] = 1;
                return 1;
            } else if (idx == -1 && sum != target) {
                dp[{idx, sum}] = 0;
                return 0;
            }

            dp[{idx, sum}] = dfs(idx - 1, sum + nums[idx]) + dfs(idx - 1, sum - nums[idx]);
        } 

        return dp[{idx, sum}];

    }

    int findTargetSumWays(vector<int>& nums_, int target_) {
        nums = nums_;
        target = target_;

        return dfs(nums.size()-1, 0);


        
    }
};