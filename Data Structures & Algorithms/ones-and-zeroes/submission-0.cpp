class Solution {
public:
    // vector<string> strs;

    // unordered_map<pair<int,int>, int, [](pair<int,int>& p){return std::hash<long>{}((p.first << 32) + p.second);}> dp;

    // int dfs(int M, int N, int i ) {
    //     if (i >= strs.size()) {return 0;}

    //     int m_i = 0;
    //     int n_i = 0;
    //     for (char ch: strs[i]) {
    //         if (ch == '0') {++m_i;}
    //         else if (ch == '1') {++n_i;}
    //     }
    //     if (M - m_i < 0 || N - n_i < 0) {
    //         return dfs(M,N, i+1);
    //         dp[{M,N}]
    //     }

    // return max(
    //     dfs(M - m_i, N - n_i, i + 1) + 1,
    //     dfs(M, N, i+1)
    // );
    // }

    int findMaxForm(vector<string>& strs, int M, int N) {
        vector<vector<int>> dp(M+1, vector<int>(N+1, 0));

        for (int t = 0; t < strs.size(); ++t) {
            vector<vector<int>> dpm = dp;

            int m = 0;
            int n = 0;
            for (char ch: strs[t]) {
                if (ch == '0') {++m;}
                else if (ch == '1') {++n;}
            }

            for (int i = 0; i < M+1; ++i) {
                for (int j = 0; j < N+1; ++j) {
                    if (i >= m && j >= n) {
                        dpm[i][j] = max(dpm[i][j], dp[i - m][j-n] +1);
                    }
                }
            }

            dp = dpm;
            
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