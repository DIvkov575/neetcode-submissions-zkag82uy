struct pt {
    int x;
    int y;
    int d;
};

#include<queue>
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int,int>> ds = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        deque<pt> dq;

        for (int i =0; i < n; ++i) {
            for (int j =0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    dq.push_back({i,j,0});
                }
            }
        }

        int maxd = 0;

        while (!dq.empty()) {
            auto [x,y,d] = dq.front();
            dq.pop_front(); 
            maxd = max(maxd, d);

           for (auto [dx, dy]: ds) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }

                if (grid[ny][nx] == 1) {
                    grid[ny][nx] = 2;
                    dq.emplace_back(nx,ny,d+1);
                }
           }
        }

        for (int i =0; i < n; ++i) {
            for (int j =0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return maxd;
        

    }
};