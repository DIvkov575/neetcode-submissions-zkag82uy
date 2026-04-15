#include<queue>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output(nums.size() - k + 1);

        deque<pair<int, int>> pq;
        for (int i = 0; i < k; ++i) { 
            while (!pq.empty() && nums[i] > pq.back().first) {
                pq.pop_back();
            }
            pq.push_back({nums[i], i});
        }

        // output.push_back(pq.front().first);

        for (int i = 0; i < nums.size() - k + 1; ++i) {
            while (pq.front().second < i) { pq.pop_front(); }
            output[i] = pq.front().first;
            
            while (!pq.empty() && nums[k+i] > pq.back().first) {pq.pop_back();}
            pq.push_back({nums[k+i], k+i});

        }


        return output;

        
    }
};
