class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(),
            col = matrix[0].size();
        
        // check if target overshoot matrix
        if (target < matrix[0][0] || matrix[row - 1][col - 1] < target)
            return false;

        int l = 0,
            r = row * col - 1;
        
        while (l <= r) {
            int m = l + (r - l)/2,
                v = matrix[m / col][m % col];
            if (target < v) {
                r = m - 1;
            } else if (target > v) {
                l = m + 1;
            } else /* target == v */ { 
                return true;
            }
        }
        
        return false;
    }
};