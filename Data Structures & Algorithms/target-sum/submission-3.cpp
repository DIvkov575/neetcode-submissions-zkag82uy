#include <vector>
#include <unordered_map>
using namespace std;

struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<long long>()(((long long)p.first << 32) ^ p.second);
    }
};

class Solution {
public:
    vector<int> nums;
    int target;

    unordered_map<pair<int,int>, int, PairHash> memo;

    int dfs(int idx, int sum) {
        if (idx == nums.size())
            return sum == target;

        pair<int,int> key = {idx, sum};
        if (memo.contains(key))
            return memo[key];

        int res =
            dfs(idx + 1, sum + nums[idx]) +
            dfs(idx + 1, sum - nums[idx]);

        memo[key] = res;
        return res;
    }

    int findTargetSumWays(vector<int>& nums_, int target_) {
        nums = nums_;
        target = target_;
        return dfs(0, 0);
    }
};