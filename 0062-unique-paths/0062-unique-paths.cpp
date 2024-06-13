class Solution {
public:
    auto helper(int m, int n, std::vector<std::vector<int>> &res) -> int {
        if (m == 1 || n == 1) {
            return 1;
        }
        
        if (res[m][n]) {
            return res[m][n];
        }
        
        return res[m][n] = helper(m - 1, n, res) + helper(m, n - 1, res);
    }
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> res (m + 1, std::vector(n + 1,0));
        return helper(m,n,res);
    }
};