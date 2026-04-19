#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > total) return 0;
        if ((target + total) % 2) return 0;

        int P = (target + total) / 2;

        vector<int> dp(P + 1, 0);
        dp[0] = 1;

        for (int n : nums) {
            for (int s = P; s >= n; s--) {
                dp[s] += dp[s - n];
            }
        }

        return dp[P];
    }
};