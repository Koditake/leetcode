class Solution {
public:
    void buildDistance(std::queue<pair<int,int>>& q, int n, std::vector<std::vector<int>>& dis, std::vector<std::vector<bool>>& vis) {
        std::vector<std::pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int lvl = 0;

        while (!q.empty()) {
            int siz = q.size();
            while (siz--) {
                auto [x,y] = q.front();
                q.pop();
                dis[x][y] = lvl;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dir[i].first, ny = y + dir[i].second;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]) {
                        q.push({nx,ny});
                        vis[nx][ny] = true;
                    }
                }
            }
            ++lvl;
        }
    }
    
    int findSf(vector<vector<int>>& dis, int n){
        std::priority_queue<pair<int,pair<int,int>>> pq;
        std::vector<std::vector<bool>> vis (n,std::vector<bool>(n));
        
        pq.push({dis[0][0],{0,0}});
        vis[0][0] = true;
        
        std::vector<std::pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int res = INT_MAX;
        
        while(!pq.empty()){
            auto [d,cord] = pq.top();
            pq.pop();
            
            int x = cord.first, 
                y = cord.second;
            
            res = std::min(res,dis[x][y]);
            if(x == n-1 && y == n-1) return res;
            for(int i = 0; i < 4; i++){
                int nx = x + dir[i].first, ny = y + dir[i].second;
                if(nx >= 0 && nx < n && ny >= 0 && ny < n &&!vis[nx][ny]){
                    vis[nx][ny] = true;
                    pq.push({dis[nx][ny],{nx,ny}});
                }
            }
        }
        return res;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m = grid.size(),
            n = grid[0].size();
        
        std::queue<pair<int, int>> q;
        std::vector<std::vector<bool>> vis (n,std::vector<bool>(n));

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    vis[r][c] = true;
                    q.push({r, c});
                }
            }
        }
        
        std::vector<std::vector<int>> dis (n,std::vector<int>(n));

        buildDistance(q,n,dis,vis);
        
        return findSf(dis,n);
    }
};