class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),
            n = matrix[0].size(),
            l = 0, r = n - 1,
            h = 0, k = m - 1;

        if (matrix[0][0] > target || matrix[m - 1][n - 1] < target) {
            // matrix range is overmachted by target
            return false;
        }
        
        while (h <= k) {
            int mid = h + (k - h)/2;
            if (target == matrix[mid][0] || target == matrix[mid][n - 1]) {
                //found target
                return true;
            } else if (target > matrix[mid][0] && target < matrix[mid][n - 1]) {
                // found the row where target is -> exit
                h = mid;
                break;
            } else if (target < matrix[mid][0]) {
                k = mid - 1;
            } else {
                h = mid + 1;
            }
        }
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target == matrix[h][mid]) {
                return true;
            } else if (target < matrix[h][mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return false;
    }
};