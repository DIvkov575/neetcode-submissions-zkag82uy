class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum%k;
        // int sum = 0;       
        // for (int num: nums) {
        //     sum += num%k;
        // }
        // return sum;
    }
};
