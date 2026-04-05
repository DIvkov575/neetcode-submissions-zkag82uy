class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> valid = {1,2,3,4,5,6,7,8,9};

        // validate row
        for (int i = 0; i<board[0].size(); ++i) {
            unordered_set<int> buf;
            for (int row = 0; row< board.size(); ++row) {
                if (board[row][i] != '.') {
                    if (buf.count(board[row][i]) == 0) {
                        buf.insert(board[row][i]);
                    } else {
                        return false;
                    }
    
                }
            }
        }



        // validate row
        for (int i = 0; i< 9; ++i) {

            unordered_set<int> buf;
            // actually check row 
            for (int col = 0; col< board.size(); ++col) {
                if (board[i][col] != '.') {
                    if (buf.count(board[i][col]) == 0) {
                        buf.insert(board[i][col]);
                    } else {
                        return false;
                    }
    
                }
            }

        }

        //validate cells 
        auto validateCell = [board](int r,int c) -> bool{
            unordered_set<int> buf;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j<3; ++j) {
                    if (board[r+i][c+j] != '.') {
                        if (buf.count(board[r +i][c+j]) == 0) {
                            buf.insert(board[r+i][c+j]);
                        } else {
                            return false;
                        }
                    }
                }
            }
            return true;
        };

        for (int i = 0; i<3; ++i) {
            for (int j =0 ; j<3; ++j) {
                if (!validateCell(3*i, 3*j)) {
                    return false;
                }
            }
        }



        return true;


        
     
    }
};
