class Solution {
public:
    int glob_max;
    int total = 0;
    unordered_map<int, int> counts;

    // assumes counts contains somethign bc totla > 0
    int getmv() {
        int mv = glob_max;
        for (auto& [key, value] : counts) {
            if (value > 0) {
                mv = min(key, mv);
            }
        }
        return mv;
    }

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        for (int h : hand) {
            ++counts[h];
            ++total;
        }

        glob_max = *std::max_element(hand.begin(), hand.end());

        while (total > 0) {
            int mv = getmv();
            for (int i = 0; i < groupSize; ++i) {
                if (counts[mv] > 0) {
                    --counts[mv];
                    --total;
                    ++mv;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};