class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> output;
        output.reserve(nums1.size());

        // size_t p2;
        for (int num: nums1) {
            size_t p1 = 0;
            while (p1 < nums2.size() && nums2[p1] != num) p1++;
            size_t p2 = p1 + 1;
            while (p2 < nums2.size() && nums2[p2] <= num) p2++;
            if (p2 >= nums2.size()) {
                output.push_back(-1);
            } else {
                output.push_back(nums2[p2]);
            }
        }

        return output;
        
    }
};