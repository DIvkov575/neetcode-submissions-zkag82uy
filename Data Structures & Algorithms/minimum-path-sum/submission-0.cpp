#include<climits>

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        
        dp[0][0] = grid[0][0];

        vector<pair<int, int> > ds = {{0,1}, {1,0}};
        for (int i =0; i < n; ++i) {
            for (int j =0; j < m; ++j) {

                for (auto [dx, dy]: ds) {
                    int ny = i + dy;
                    int nx = j + dx;

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                        continue;
                    }

                    dp[ny][nx] = min(dp[ny][nx],dp[i][j] + grid[ny][nx]);
                

                }
                
    
            }
        }


        // int acc = grid[n-1][m-1];

        // int x = m-1;
        // int y = n-1;
        // int l = x + y ;
        // while (x != 0 || y != 0) {
        //     int s1, s2;
        //     if (x - 1 < 0) {
        //         s1 = INT_MAX;
        //     } else {
        //         s1 = dp[y][x-1];
        //     }

        //     if (y - 1 < 0) {
        //         s2 = INT_MAX;
        //     } else {
        //         s2 = dp[y-1][x];
        //     }

        //     if (s1 == INT_MAX && s2 == INT_MAX) {
        //         break;
        //     }

        //     if (s1 < s2) {
        //         acc += grid[y][x-1];
        //         x = x-1;
        //     } else {
        //         acc += grid[y-1][x];
        //         y = y-1;
        //     }

        // }

        // return acc;

        return dp[n-1][m-1];
        
    }
};