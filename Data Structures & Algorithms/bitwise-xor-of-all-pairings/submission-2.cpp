class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int total = 0;

        if (m%2 == 1) {
            for (int i = 0; i < nums1.size(); ++i) {
                total ^= nums1[i];
            }
        }
        if (n%2 == 1) {
            for (int i = 0; i < m; ++i) {
                total ^= nums2[i];
            }
        }


return total;

    }
};
