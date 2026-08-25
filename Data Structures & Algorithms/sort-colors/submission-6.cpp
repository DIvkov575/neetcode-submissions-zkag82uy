class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int lptr = 0;
        int rptr = n-1;


        int ptr = 0;
        while (ptr <= rptr) {
            if (nums[ptr] == 0) {
                if (ptr == lptr) {
                    swap(nums[ptr++], nums[lptr++]);
                } else {
                    swap(nums[ptr], nums[lptr++]);
                }
            } else if (nums[ptr] == 2) {
                swap(nums[ptr], nums[rptr--]);
            } else {
                ++ptr;
            }

        }
        

    }
};