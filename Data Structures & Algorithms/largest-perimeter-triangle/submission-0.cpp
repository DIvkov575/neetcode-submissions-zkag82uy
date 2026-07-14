class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i <= nums.size()-3; i++) {
            int num_a = nums[nums.size()-3-i];
            int num_b = nums[nums.size()-2-i];
            int num_c = nums[nums.size()-1-i];

            if (num_a + num_b > num_c) {
                return num_a + num_b + num_c;
            }
        }
        
        return 0;
    }
};
