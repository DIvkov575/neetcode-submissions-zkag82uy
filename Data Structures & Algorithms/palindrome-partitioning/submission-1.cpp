class Solution {
public:
    string s;
    vector<vector<bool>> dp;

    void build_dp() {
        int n = s.size();
        dp.assign(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) dp[i][i] = true;

        for (int i = 0; i < n - 1; ++i)
            dp[i][i + 1] = (s[i] == s[i + 1]);

        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }
    }

    vector<vector<string>> solutions;
    vector<string> solution;

    void dfs(int idx) {
        if (idx == s.size()) {
            solutions.push_back(solution);
            return;
        }

        for (int i = idx; i < s.size(); ++i) {
            if (dp[idx][i]) {
                solution.push_back(s.substr(idx, i - idx + 1));
                dfs(i + 1);
                solution.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s_) {
        s = s_;
        solutions.clear();
        solution.clear();

        build_dp();
        dfs(0);

        return solutions;
    }
};