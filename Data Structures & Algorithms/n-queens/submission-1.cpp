#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<string> board;

    vector<bool> qc;
    vector<bool> qd;
    vector<bool> qa;

    void dfs(int r) {
        int n = board.size();
        if (r == n) {
            res.push_back(board);
        }

        for (int c = 0; c < n; ++c) {
            if (!qc[c] && !qd[r-c] && !qa[r+c]) {
                qc[c] = true;
                qd[r-c] = true;
                qa[r+c] = true;

                board[r][c] = 'Q';
                dfs(r+1);
                board[r][c] = '.';

                qc[c] = false;
                qd[r-c] = false;
                qa[r+c] = false;
            }
            
        }

    }


    vector<vector<string>> solveNQueens(int n) {
        string empty(n, '.');
        board = vector<string>(n, empty);
        res.clear();
        
        qc = vector<bool>(n, false);
        qd = vector<bool>(2*n - 1, false);
        qa = vector<bool>(2*n - 1, false);

        dfs(0);

        return res;
        
    }
};
