class Solution {
public:
    auto counter(std::vector<int> &row, int row_s, int col_s) -> int {
        int l = 0,
            r = col_s - 1;
        
        while (l <= r) {
            int m = l + (r - l)/2;
            
            if (row[m] < 0) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        
        return col_s - l;
    }
    
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0,
            row_s = grid.size(),
            col_s = grid[0].size();
        
        for (auto &row:grid) {
            res += counter (row, row_s, col_s);
        }
        
        return res;
    }
};