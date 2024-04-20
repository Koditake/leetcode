class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (land[i][j]) {
                    int x = i, y = j;
                    for (x = i; x < m && land[x][j]; ++x)
                        for (y = j; y < n && land[x][y]; ++y)
                            land[x][y] = 0;
                    res.push_back({i, j, x - 1, y - 1});
                }
            }
        return res;
    }
};