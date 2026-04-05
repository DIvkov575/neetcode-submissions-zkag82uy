class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_vol = {};
        
        int l = 0;
        int r = height.size()-1;
        while (l < r){
            max_vol = max(max_vol, (r-l)*min(height[l], height[r]));

            (height[l] >= height[r]) ? r--: ++l;


        }

        return max_vol; 
         
    }
};
