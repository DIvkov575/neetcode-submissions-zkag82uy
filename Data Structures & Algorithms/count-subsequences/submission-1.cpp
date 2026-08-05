class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int>dp(t.size());

        for (char c: s) {
            for (int i = t.size()-1; i >0; --i) {
                if (c == t[i]) {
                    dp[i] += dp[i-1];
                }
            }
            if (c == t[0]) ++dp[0];
        }
        return dp[t.size()-1];
    }
};
