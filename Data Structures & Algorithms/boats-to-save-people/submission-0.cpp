class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ctr{};
        int n = people.size();
        sort(people.begin(), people.end());

        int r = n- 1, l = 0;
        for (; l <= r; ++l) {
            while (l < r && people[l] + people[r] > limit) {
                ++ctr;
                --r;
            }
            // l == r || ppl l  + pplr < limit
            ++ctr;
            --r;

        }

        return ctr;
    }
};