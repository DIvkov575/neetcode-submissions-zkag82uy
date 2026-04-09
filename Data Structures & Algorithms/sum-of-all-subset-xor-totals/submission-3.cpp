class Solution {
    int dfs(const vector<int>& nums, int buf, int idx) {
        if (idx >= nums.size()) {
            return buf;
        }

        int acc = 0;
        acc += dfs(nums, buf^nums[idx], idx+1);
        acc += dfs(nums, buf, idx+1);
        return acc;
        
    }

public:
    int subsetXORSum(vector<int>& nums) {

        return dfs(nums, 0, 0);
        
    }
};