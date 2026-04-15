class Solution {
public:
    void qsort(int a, int b, vector<int>& nums) {
        if (a >= b) { return;}

        int pivot = nums[b];
        int r = b-1;
        int l = a;

        cout << a << b << endl;

        while (true) {
            while (l <= r && nums[l] < pivot) {++l;}
            while (l <= r && nums[r] > pivot) {--r;}
            if (l > r) break;
            swap(nums[l++], nums[r--]);
        }
        if (l < b) {
            swap(nums[l], nums[b]);
        }

        qsort(a, l-1, nums);
        qsort(l+1, b, nums);
        return;
    }


    vector<int> sortArray(vector<int>& nums) {
        qsort(0, nums.size()-1, nums);
        return nums;
        
    }
};