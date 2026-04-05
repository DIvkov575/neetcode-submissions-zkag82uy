class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> val_idx_map(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            val_idx_map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i) { 
            unordered_map<int, int>::iterator co_idx = val_idx_map.find(target-nums[i]);
            if (co_idx != val_idx_map.end() && co_idx->second != i) {
                return {i, co_idx->second};
            }
        }

        return {-1, -1};
}
    };

