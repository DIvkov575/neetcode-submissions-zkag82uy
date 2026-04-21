class Solution {
public:
int mincostTickets(vector<int>& days, vector<int>& costs) {
    int n = days.size();
    vector<int> dp(n + 1, 0);

    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i] + costs[0];

        int j = i;
        while (j >= 0 && days[i] - days[j] < 7) j--;
        dp[i + 1] = min(dp[i + 1], dp[j + 1] + costs[1]);

        j = i;
        while (j >= 0 && days[i] - days[j] < 30) j--;
        dp[i + 1] = min(dp[i + 1], dp[j + 1] + costs[2]);
    }

    return dp[n];
}
};