class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int maxa = 0;
        int maxb = 0;
        int maxc = 0;

        for (auto& trip: triplets) {
            if(trip == target)
            {
                return true; 
            }
            if (trip[0] > target[0] || trip[1] > target[1] || trip[2] > target[2]) {
                continue;
            }

            maxa = max(maxa, trip[0]);
            maxb = max(maxb, trip[1]);
            maxc = max(maxc, trip[2]);

        }

        if (maxa == target[0] && 
            maxb == target[1] &&
            maxc == target[2]) {
                return true;
            } else {
                return false;
            }
        
    }
};
