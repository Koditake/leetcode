class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int l = original.size(),
            l0 = 0;

        if (m*n != l) return {};
        std::vector<std::vector<int>> res (m,std::vector<int> (n,0));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                res[i][j] = original[l0];
                l0++;
            }
        
        return res;
    }
};