#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 0) return -1;
        vector<int> memo(amount + 1, INT_MAX);
        memo[0] = 0;
        for (int n = 1; n <= amount; ++n) {
            for (int c : coins) {
                if (c <= n && memo[n - c] != INT_MAX) {
                    memo[n] = min(memo[n], memo[n - c] + 1);
                }
            }
        }
        return memo[amount] == INT_MAX ? -1 : memo[amount];
    }
};