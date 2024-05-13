class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(),
            n = grid[0].size();
        
        // if the leading bit is 0 --> toggle it
        for (int i = 0; i < m; ++i) {
            if(grid[i][0] == 0) {
                for(int j = 0; j < n; ++j) {
                    grid[i][j] ^= 1;
                }
            }
        }
        
        // process each col (except leading col)
		// if the numbers of 1 is larger than m/2 (where m is the row nums), toggle it.
        for (int i = 1; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < m; ++j) {
                cnt += grid[j][i];
            }            
            if (cnt <= (m >> 1)) {
                for(int j = 0; j < m; ++j) {
                    grid[j][i] ^= 1;
                }
            }
        }
        
        // calculate the result
        int res = 0, 
            bin = 1;
        for (int j = n-1; j >= 0; --j) {
            for(int i = 0; i < m; ++i) {
                res += grid[i][j]*bin;
            }
            bin = (bin << 1);
        }
        
        return res;
    }
};