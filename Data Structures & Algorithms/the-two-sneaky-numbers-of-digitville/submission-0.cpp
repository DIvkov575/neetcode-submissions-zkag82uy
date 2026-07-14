class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> output;

        int true_sum = (nums.size()-2) * (nums.size()-3) / 2;
        int sum = accumulate(nums.begin(), nums.end(), 0);

        unordered_set<int> unique = {};
        for (int num: nums) {
            if (unique.contains(num)) {
                output.push_back(num);
                break;
            } else {
                unique.insert(num);
            }
        }

        output.push_back(sum - true_sum - output[0]);

        return output;
    }
};
