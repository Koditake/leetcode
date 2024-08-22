class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0},
            col[9][9] = {0},
            box[3][3][9] = {0};
        
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] != '.') {
                    auto tmp = board[r][c] - '1';
                    if (row[r][tmp] > 0) return false; else row[r][tmp] += 1;
                    if (col[c][tmp] > 0) return false; else col[c][tmp] += 1;
                    if (box[r/3][c/3][tmp] > 0) return false; else box[r/3][c/3][tmp] += 1;
                }
            }
        }
        
        return true;
    }
};