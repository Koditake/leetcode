class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> row (n,vector<int>(n,0)), 
                            col (n,vector<int>(n,0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                auto tmp = matrix[i][j] - 1;
                if (row[i][tmp] > 0) return false; else ++row[i][tmp];
                if (col[j][tmp] > 0) return false; else ++col[j][tmp];
            }
        }
        return true;
    }
};