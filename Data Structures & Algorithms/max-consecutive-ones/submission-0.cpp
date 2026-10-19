class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxc = 0;
        int ctr= 0;
        for (int i =0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ctr = 0;
            } else {
                ++ctr;
                maxc = max(maxc, ctr);
            }
        }

        return maxc;
        
    }
};