class Solution {
    int xorSum = 0;
    void dfs(const vector<int>& nums, int buf, int idx) {
        if (idx >= nums.size()) {
            xorSum += buf;
            return;
        }


        dfs(nums, buf^nums[idx], idx+1);
        dfs(nums, buf, idx+1);
    }

public:
    int subsetXORSum(vector<int>& nums) {

        dfs(nums, 0, 0);
        return xorSum;
        
    }
};