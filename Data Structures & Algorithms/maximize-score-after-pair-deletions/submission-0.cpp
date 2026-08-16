class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 0;
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (n%2==1) {
            return total -  *std::min_element(nums.begin(), nums.end());
        }
        int mb = nums[0] + nums[1];
        int buf = nums[0] + nums[1];
        for (int i = 2; i < nums.size(); ++i) {
            buf -= nums[i-2];
            buf += nums[i];
            mb = min(mb, buf);
        }
        return total - mb;
    }
};
