class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> output;
        output.reserve(nums.size());

        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] != nums[i + 1]) {
                output.push_back(nums[i]);
            }
        }

        output.push_back(nums.back());
        nums = output;
        return nums.size();
        
    }
};