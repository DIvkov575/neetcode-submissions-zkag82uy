class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> unique;
        for (int num: nums) {
           if (unique.count(num) == 0) {
            unique.insert(num);
           } else {
            return true;
           }
        }
        return false;
        
    }
};