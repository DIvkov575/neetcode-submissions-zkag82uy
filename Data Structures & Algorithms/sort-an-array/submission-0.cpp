class Solution {
public:
    void qsort(int a, int b, vector<int>& nums) {
        if (a >= b) return;

        int pivot = nums[b];
        int l = a;
        int r = b - 1;

        while (true) {
            while (l <= r && nums[l] <= pivot) ++l;
            while (l <= r && nums[r] >= pivot) --r;

            if (l > r) break;
            std::swap(nums[l++], nums[r--]);
        }

        std::swap(nums[l], nums[b]);  // place pivot

        qsort(a, l - 1, nums);
        qsort(l + 1, b, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        if (!nums.empty())
            qsort(0, nums.size() - 1, nums);
        return nums;
    }
};