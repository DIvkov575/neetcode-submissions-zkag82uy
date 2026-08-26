class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int,int>> ds = {{0,1}, {1,0}, {-1, 0}, {0, -1}};

        map<int, vector<pair<int, int>>> levels= { {grid[0][0], vector<pair<int,int>>{{0,0}}} };

        while (!levels.empty()) {
            auto [t, elems] = *levels.begin();
            levels.erase(t);

            deque<pair<int,int>> q(elems.begin(), elems.end());

            while (!q.empty()) {
               auto [cx, cy] = q.front();
               q.pop_front();

                if (cx == n-1 && cy == n-1) {return t;}
                if (grid[cx][cy] == -1) {continue;}
                grid[cx][cy] = -1;

                for (auto [dx, dy]: ds) {
                    int nx = cx+dx, ny = cy+dy;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny]==-1) { continue; }
                    int nt = grid[nx][ny];

                    if (nt <= t) {
                        q.push_back({nx,ny});
                    } else {
                        levels[nt].push_back({nx,ny});
                    }

                }

            }
        }

        return -1;
    }
};
