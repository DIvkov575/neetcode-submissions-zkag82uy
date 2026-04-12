#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>

struct PairHash {
    size_t operator()(const std::pair<int,int>& p) const {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};

class Solution {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        std::queue<std::pair<int,int>> q;
        std::unordered_set<std::pair<int,int>, PairHash> visited;

        std::vector<int> dx = {0,0,1,-1};
        std::vector<int> dy = {1,-1,0,0};

        bool found = false;
        for (int i = 0; i < n && !found; ++i) {
            for (int j = 0; j < m && !found; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i,j});
                    visited.insert({i,j});
                    found = true;
                }
            }
        }

        int perimeter = 0;

        while (!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    perimeter++;
                    continue;
                }


                if (grid[nx][ny] == 0) {
                    perimeter++;
                    continue;
                }


                if (!visited.count({nx,ny})) {
                    visited.insert({nx,ny});
                    q.push({nx,ny});
                }
            }
        }

        return perimeter;
    }
};