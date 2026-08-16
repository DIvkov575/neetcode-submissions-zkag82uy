class Solution {
public:
    long long largestEvenSum(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        long long total = 0;
        for (int i = 0; i < k; ++i) { total += nums[i]; }
        if (total %2==0) {return total;}
        else if (k == n) {return -1;}
        int kpar = nums[k-1]%2;
        int kpar_pair_idxa = -1;
        for (int i = k; i < n; ++i) {
            if ((nums[i]%2^1) == kpar) {
                kpar_pair_idxa = i;
                break;
            }
        }
        int kpar_pair_idxb = -1;
        for (int i = k-2; i >= 0; --i) {
            if ((nums[i]%2^1) == kpar) {
                kpar_pair_idxb = i;
                break;
            }
        }
        if (kpar_pair_idxa == -1 && kpar_pair_idxb == -1) {
            return -1;
        } else if (kpar_pair_idxa == -1 && kpar_pair_idxb != -1) {
            return total - nums[kpar_pair_idxb] + nums[k];
        } else if (kpar_pair_idxa != -1 && kpar_pair_idxb == -1) {
            return total - nums[k-1] + nums[kpar_pair_idxa];
        } else {
            return max(
                total - nums[k-1] + nums[kpar_pair_idxa],
                total - nums[kpar_pair_idxb] + nums[k]
            );
        }
    }
};
