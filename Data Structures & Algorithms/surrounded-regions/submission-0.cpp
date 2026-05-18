class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size()-1;
        int m = board[0].size()-1;


        vector<pair<int, int>> ds = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
        set<pair<int, int>> visited; // lowk needs to be unordered

        
        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[0].size(); ++c) {
                vector<pair<int, int>> group = {};
                bool flag = false;
                deque<pair<int, int>> dq;

                if (r == 0 || r == n || c == 0 || c == m) {
                    flag = true;
                }

                if (board[r][c] == 'X' || visited.contains({r,c})) {
                    continue;
                }

                visited.insert({r,c});

                group.push_back({r,c});
                dq.push_back({r,c});

                while (!dq.empty()) {
                    auto [curr, curc] = dq.front();
                    dq.pop_front();

                    for (auto [dr, dc]: ds) {
                        int nr = dr + curr;
                        int nc = dc + curc;

                        if (nr < 0 || nr > n || nc < 0 || nc > m ||
                            board[nr][nc] == 'X' ||
                            visited.contains({nr, nc})) {
                            continue;
                        }
                        
                        if (nr == 0 || nr == n || nc == 0 || nc == m) {
                            flag = true;
                        }
                        
                        visited.insert({nr,nc});
                        group.push_back({nr,nc});
                        dq.push_back({nr,nc});
                    }

                }

                if (!flag) {
                    for (auto [cr, cc]: group) {
                        board[cr][cc] = 'X';
                    }
                }

            }
        }
    }
};
