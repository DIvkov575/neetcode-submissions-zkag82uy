#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        deque<pair<int,int>> dq;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) {
                    dq.push_back({r, c});
                }
            }
        }

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            for (int i = 0; i < 4; ++i) {
                int rn = r + dr[i];
                int cn = c + dc[i];

                if (rn < 0 || cn < 0 || rn >= m || cn >= n) continue;

                if (grid[rn][cn] > grid[r][c] + 1) {
                    grid[rn][cn] = grid[r][c] + 1;
                    dq.push_back({rn, cn});
                }
            }
        }
    }
};