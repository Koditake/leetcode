

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i,int j)
    {

        int ans = 0,
            temp = 0;
        if (i >= grid.size() || i<0 || j<0 || j >= grid[0].size() || grid[i][j] == 0) 
            return 0;
        temp = grid[i][j];
        grid[i][j] = 0;
        ans = max(ans,dfs(grid,i-1,j));
        ans = max(ans,dfs(grid,i+1,j));
        ans = max(ans,dfs(grid,i,j+1));
        ans = max(ans,dfs(grid,i,j-1));
        grid[i][j] = temp;
        return ans + temp;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>0){
                    ans = max(ans,dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
};