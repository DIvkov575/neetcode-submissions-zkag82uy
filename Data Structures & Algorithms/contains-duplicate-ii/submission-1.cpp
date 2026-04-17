class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> num_idx;

        for (int i =0; i < nums.size(); ++i) {
            auto iter = num_idx.find(nums[i]);
            if (iter != num_idx.end()) {
                if (i - iter->second <= k) {
                    return true;
                }
            }
            num_idx[nums[i]] = i;
        }

        return false;
        
    }
};