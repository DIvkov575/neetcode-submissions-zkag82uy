class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        vector<int> buf(nums.end() - k, nums.end());
        nums.insert(nums.begin(), buf.begin(), buf.end());
        nums.resize(nums.size() - k);
        
        
    }
};