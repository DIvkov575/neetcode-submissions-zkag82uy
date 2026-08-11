class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cts[3] = {};
        if (bills[0] !=5) {
            return false;
        }
        ++cts[0];

        for (int i = 1; i < bills.size(); ++i) {
            if (bills[i] == 20) {
                if (cts[1] >= 1 && cts[0] >= 1) {
                    --cts[0];
                    --cts[1];
                } else if (cts[0] >= 3) {
                    cts[0] -= 3;
                } else {
                    return false;
                }
            } else if (bills[i] == 10) {
                if (cts[0] > 0) {
                    --cts[0];
                    ++cts[1];
                } else {
                    return false;
                }
            } else {
                ++cts[0];
            }
        }
        return true;
        

        
    }
};