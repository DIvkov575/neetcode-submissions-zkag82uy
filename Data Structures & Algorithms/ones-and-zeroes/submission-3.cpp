class Solution {
public:


    int findMaxForm(vector<string>& strs, int M, int N) {
        vector<vector<int>> dp(M+1, vector<int>(N+1, 0));

        for (int t = 0; t < strs.size(); ++t) {
            int m = 0;
            int n = 0;
            for (char ch: strs[t]) {
                if (ch == '0') {++m;}
                else if (ch == '1') {++n;}
            }

            for (int i = M; i >= m; --i) {
                for (int j = N; j >= n; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - m][j-n] +1);
                }
            }
        }

        // find max
        int max_val = 0;
        for (vector<int> row: dp) {
            for (int elem: row) {
                max_val = max(max_val, elem);
            }
        }

        return max_val;
               
    }
};