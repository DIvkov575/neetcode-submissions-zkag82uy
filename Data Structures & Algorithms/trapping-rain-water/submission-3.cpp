class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;

        int mlh = 0, mrh = 0;
        int total_vol = 0;

        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] >= mlh) {
                    mlh = height[l];
                } else {
                    total_vol += mlh - height[l];
                }
                l++;
            } else {
                if (height[r] >= mrh) {
                    mrh = height[r];
                } else {
                    total_vol += mrh - height[r];
                }
                r--;
            }
        }

        return total_vol;
    }
};