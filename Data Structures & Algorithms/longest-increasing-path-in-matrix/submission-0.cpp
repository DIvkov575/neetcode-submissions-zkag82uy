class Solution {
public:
    int n;
    int m;
    int gmx;
    vector<vector<int>> dp;
    vector<pair<int,int>> ds = {{1,0}, {-1, 0}, {0,1}, {0, -1}};
    vector<vector<int>> _matrix;

    int dfs(int cx, int cy) {
        int mx{0};
        if (dp[cx][cy] == -1) {
            for (auto [dx, dy]: ds) {
                int x = dx+cx, y = dy+cy;

                if (
                    x >= n ||
                     x < 0 ||
                    y >= m ||
                     y < 0 ||
                     _matrix[x][y] >= _matrix[cx][cy]
                ) {continue;}
            
                mx = max(mx, dfs(x,y)+1);
            }
            dp[cx][cy]=mx;
            gmx = max(gmx, mx);
        } else {
            mx = dp[cx][cy];
        }
 
        return mx;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        gmx = 0;
        _matrix = matrix;
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dfs(i,j);
            }
        }
        return gmx+1;
    }
};
