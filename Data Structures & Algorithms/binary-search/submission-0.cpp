class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() -1;
        while (low < high) {
            int mid = (low + high + 1) / 2;

            if (target >= nums[mid]) {
                low = mid;
                // low = mid + 1;
            } else {
                // high = mid;
                high = mid - 1;
            }
        }

        if (nums[low] == target) {
            return low;
        } else {
            return -1;
        }
         
    }
};
