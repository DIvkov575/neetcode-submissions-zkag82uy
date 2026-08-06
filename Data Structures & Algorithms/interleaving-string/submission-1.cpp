class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m =s1.size();
        int n =s2.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        if (s1.size() + s2.size() != s3.size()) {return false;}
        if (s1.empty()) {return s2 == s3;}
        if (s2.empty()) {return s1 == s3;}

        dp[0][0] = true;

        for (int i = 1; i <= m; ++i) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }

        for (int j = 1; j <=n ; ++j) {
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        for (int i = 1; i <=m; ++i) {
            for (int j = 1; j <=n; ++j) {
                dp[i][j] =
                    (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                    (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);

                // if (dp[i][j] && i + j -1 == s3.size()) {
                //     return true;
                // }
            }
        }
        // return false;
        return dp[m][n];

        
    }
};
