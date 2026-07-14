class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxa = 0;
        int alt = 0;
        for (int i =0; i < gain.size(); ++i) {
            alt += gain[i];
            maxa = max(maxa,alt);
        }
        return maxa;
        
    }
};
