class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        int mlh = height[l];
        int mrh = height[r];

        int total_vol = 0;

        // FIX: remove preprocessing loops (they break correctness)

        while (l < r) {
            if (mlh < mrh) {
                l++;
                if (l >= r) break;

                if (height[l] < mlh) {
                    total_vol += mlh - height[l];
                } else {
                    mlh = height[l];
                }
            } else {
                r--;
                if (l >= r) break;

                if (height[r] < mrh) {
                    total_vol += mrh - height[r];
                } else {
                    mrh = height[r];
                }
            }
        }

        return total_vol;
    }
};