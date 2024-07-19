class Solution {
public:
    auto check_lucky(vector<vector<int>>& matrix, int num, int a, int b) -> bool {
        int m = matrix.size(),
            n = matrix[0].size();
        
        for (int i = 0; i < m; i++)
            if (num < matrix[i][b]) 
                return false;
        
        for (int i = 0; i < n; i++)
            if (num > matrix[a][i]) 
                return false;
        
        return true;
    }
    
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        std::vector<int> res;
        int m = matrix.size(),
            n = matrix[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (check_lucky(matrix, matrix[i][j], i, j))
                    res.push_back(matrix[i][j]);
            }
        }
        
        return res;
    }
};