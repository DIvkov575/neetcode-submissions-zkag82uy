class Solution {
public:
    int checkSpeed(vector<int>& piles, int h, int k) {
        for (int pile: piles) {
            h -= (pile + k - 1)/k;
            if (h< 0) {
                return false;
            }
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int l = 1;
        int u = *std::max_element(piles.begin(), piles.end());

        while (l < u) {
            int m = (l+u)/2;
            if (checkSpeed(piles, h, m)) {
                u = m;
            } else {
                l = m+1;
            }

        }

        return u;

    }   
};
