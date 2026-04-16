class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        if (og[0][0] == 1) { return 0; }


        int n = og.size();
        int m = og[0].size();

        for (int i = 0; i < og.size(); ++i) {
            for (int j = 0; j < og[0].size(); ++j) {
                if (og[i][j] == 1) { og[i][j] = -1;}
            }
        }
        og[0][0] = 1;

        vector<int> dxs = {0,1,};
        vector<int> dys = {1, 0};

        for (int i = 0; i < og.size(); ++i) {
            for (int j = 0; j < og[0].size(); ++j) {

                if (og[i][j] == -1) {
                    continue;
                }

                for (int k = 0; k < 2; ++k)  {
                    int nx = j + dxs[k];
                    int ny = i + dys[k];


                    if (nx < 0 or nx >= m or ny < 0 or ny >=n or og[ny][nx] == -1) {
                        continue;
                    } 

                    og[ny][nx] += og[i][j];

                }

                
            }
        }

        return og[n-1][m-1];

        





        
    }
};