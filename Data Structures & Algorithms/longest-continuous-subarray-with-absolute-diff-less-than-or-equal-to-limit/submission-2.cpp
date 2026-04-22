#include<queue>

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<pair<int,int>> mq;
        deque<pair<int,int>> hq;

        int maxd = 0;

        int l = 0;
        for (int r = 0; r < nums.size(); ++r ) {
            while (!mq.empty() && mq.back().first >= nums[r]) {mq.pop_back();}
            mq.push_back({nums[r], r});
            while (!hq.empty() && hq.back().first <= nums[r]) {hq.pop_back();}
            hq.push_back({nums[r], r}); // r is necessarily in array

            while (hq.front().first - mq.front().first > limit) {
                if (l >= mq.front().second) {mq.pop_front();}
                if (l >= hq.front().second) {hq.pop_front();}
                ++l;
            } // l excluded

            maxd = max(maxd, r-l+1);
        }
        return maxd;
        
    }
};