#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Move values in [1, n] to the front; everything else is irrelevant.
        auto end = partition(nums.begin(), nums.end(),
                             [n](int x) { return x > 0 && x <= n; });

        // Build a min-heap over that range in O(n).
        make_heap(nums.begin(), end, greater<int>());

        int last = 0;
        while (nums.begin() != end) {
            int top = nums.front();              // smallest remaining value
            if (top > last + 1) return last + 1; // gap found
            last = top;                          // duplicates just reassign the same value
            pop_heap(nums.begin(), end, greater<int>()); // moves smallest to end - 1
            --end;                               // shrink the heap range
        }
        return last + 1;
    }
};