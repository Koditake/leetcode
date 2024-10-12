class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(),
            c = matrix[0].size();
        
        if (target < matrix[0][0] || target > matrix[r - 1][c - 1]) return false;
        if (target == matrix[0][0] || target == matrix[r - 1][c - 1]) return true;
        int s = 0,
            e = r * c - 1;
        
        while (s <= e) {
            int m = s + (e - s)/2,
                mid = matrix[m / c][m % c];
            if (mid < target) {
                s = m + 1;
            } else if (mid > target) {
                e = m - 1;
            } else {
                return true;
            }
        }
        
        return false;
    }
};