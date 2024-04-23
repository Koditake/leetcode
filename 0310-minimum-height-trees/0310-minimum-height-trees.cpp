class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n); 
        int indegree[n];
        memset(indegree, 0 , sizeof(indegree));
        if(n == 1){
            return {0};
        }
        
        if(n == 2){
            return {0,1};
        }
        
        for(vector<int> edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]] += 1;              
            indegree[edge[1]] += 1;              
        }
        
        queue<int> q;
        
        for(int i = 0 ; i < n ; i++ ){
            if(indegree[i] == 1){
                q.push(i);                       
            }
        }
        vector<int> ans;
   
        while( q.empty()  == false){
            int s =  q.size();                  
            ans = {};
            while(s--){                         
                int u = q.front();
                q.pop();
                ans.push_back(u);
                
                for(int adj : graph[u]){           
                    indegree[adj] -= 1;           
                    if(indegree[adj] == 1){
                        q.push(adj);                   

                    }
                }
                
            }
        }
 
        return ans;
 
    }
};