#include <array>

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if (n == 0) return 0;

        array<int,26> cnt{};
        int l = 0;
        int max_count = 0;
        int best = 0;

        for (int r = 0; r < n; ++r) {
            int idx = s[r] - 'A';
            cnt[idx] += 1;
            max_count = max(max_count, cnt[idx]);

            while ((r - l + 1) - max_count > k) {
                cnt[s[l] - 'A'] -= 1;
                ++l;
            }

            best = max(best, r - l + 1);
        }
        return best;
    }
};