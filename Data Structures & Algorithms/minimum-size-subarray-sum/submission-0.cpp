class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int sum{}, l{}, r{};
      int ml = std::numeric_limits<int>::max();
      int n = nums.size();
       
      for (int r = 0; r < n; ++r) {
        sum += nums[r];
        while (sum >= target) {
            ml = min(ml, r-l+1);
            sum -= nums[l];
            l++;
        }
      }

      ml = (ml == std::numeric_limits<int>::max()) ? 0 : ml;
      return ml;

    }
};
