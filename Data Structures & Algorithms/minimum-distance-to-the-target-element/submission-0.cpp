class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        if (nums[start] ==  target) {
            return 0;
        }

        int ld = start;
        int rd = nums.size() - start;

        for (int i = 1; i <= std::min(ld, rd); ++i) {
            if (nums[start +i] == target || nums[start - i] == target)  {
                return i;
            }
        }

        if (ld < rd) {
            for (int i = ld; i < nums.size(); ++i) {
                if (nums[i] == target) {
                    return i - start;
                }
            }
        } else {
            for (int i = start - rd; i >= 0; --i) {
                if (nums[i] == target) {
                    return start - i;
                }
            }
        }
        return -1;
        
    }
};
