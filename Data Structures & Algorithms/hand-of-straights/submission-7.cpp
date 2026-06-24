class Solution {
public:
    int total = 0;
    map<int, int> counts;

    int getmv() {
        while (!counts.empty() && counts.begin()->second == 0) {
            counts.erase(counts.begin());
        }
        return counts.begin()->first;
    }

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        for (int h : hand) {
            ++counts[h];
            ++total;
        }


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