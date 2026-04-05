class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxVol = 0;

        for (int i = 0; i < n; ++i) {
            int min_height = heights[i];
            maxVol = max(maxVol, heights[i]); 

            for (int j = i + 1; j < n; ++j) {
                min_height = min(min_height, heights[j]);
                int width = j - i + 1;       
                maxVol = max(maxVol, min_height * width);
            }
        }

        return maxVol;
    }
};
