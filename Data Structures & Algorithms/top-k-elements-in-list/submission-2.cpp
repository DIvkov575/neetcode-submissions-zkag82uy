class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int num: nums) {
            counts[num] += 1;
        }

        vector< pair<int, int> > vk_vec = {};
        for (pair<int, int> kv: counts) {
            vk_vec.push_back(pair(kv.second, kv.first));
        }

        sort(vk_vec.begin(), vk_vec.end());

        vector<int> output = {};
        for (int i = vk_vec.size()-k; i < vk_vec.size(); ++i) {
            output.push_back(vk_vec[i].second);
        }

        return output;

    }
};
