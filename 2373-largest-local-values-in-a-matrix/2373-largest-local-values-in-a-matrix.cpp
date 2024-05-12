class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        std::vector<std::vector<int>> res(n - 2, std::vector<int>(n - 2));
        for (int i = 0; i < n - 2; ++i)
            for (int j = 0; j < n - 2; ++j)
                for (int ii = i; ii < i + 3; ++ii)
                    for (int jj = j; jj < j + 3; ++jj)
                        res[i][j] = std::max(res[i][j], grid[ii][jj]);
        return res;
    }
};