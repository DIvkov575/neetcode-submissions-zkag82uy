class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i <= n; ++i) {
            if (i*i > n) { break; }
            squares.push_back(i*i);
        }

        // return squares[squares.size()-1];

        vector<int> dp(n+1, numeric_limits<int>::max());
        // dp[1] = 1;
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int square: squares) {
                if (i + square > n) {break;}
                dp[i + square] = min(dp[i+square], dp[i] + 1);
            }
        }
        return dp[n];
        
    }
};