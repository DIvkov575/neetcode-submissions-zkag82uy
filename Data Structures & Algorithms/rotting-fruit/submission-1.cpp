class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int minutes = 0;

        while (true) {
            vector<vector<int>> next = grid;
            int changed = 0;

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (grid[i][j] == 2) {
                        if (i + 1 < n && grid[i + 1][j] == 1) {
                            next[i + 1][j] = 2;
                            changed = 1;
                        }
                        if (j + 1 < m && grid[i][j + 1] == 1) {
                            next[i][j + 1] = 2;
                            changed = 1;
                        }
                    }
                }
            }

            // backward pass
            for (int i = n - 1; i >= 0; --i) {
                for (int j = m - 1; j >= 0; --j) {
                    if (grid[i][j] == 2) {
                        if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                            next[i - 1][j] = 2;
                            changed = 1;
                        }
                        if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                            next[i][j - 1] = 2;
                            changed = 1;
                        }
                    }
                }
            }

            if (!changed) break;

            grid = next;
            minutes++;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return minutes;
    }
};