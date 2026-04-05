class Solution {
public:
    int trap(vector<int>& height) {
        int total_water = 0;

        int l = {};
        int r = height.size() - 1;
        int lmax = {};
        int rmax = {};

        while (l <= r) {
            if (lmax <= rmax) {
                if (height[l] >= lmax ) {
                    lmax = height[l];
                } else {
                    total_water += lmax-height[l];
                }
                ++l;
            } else {
                if (height[r] >= rmax ) {
                    rmax = height[r];
                } else {
                    total_water += rmax-height[r];
                }
                --r;
            }
        }

        return total_water;
    }
};