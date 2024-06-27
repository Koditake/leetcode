class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        std::unordered_map<int, int> starchart;
        std::vector<int> res (2,0);
        for (auto &edge:edges) {
            ++starchart[edge[0]];
            ++starchart[edge[1]];
            
            if (starchart[edge[0]] > res[1]) {
                res[0] = edge[0];
                res[1] = starchart[edge[0]];
            }
            
            if (starchart[edge[1]] > res[1]) {
                res[0] = edge[1];
                res[1] = starchart[edge[1]];
            }
        }
        
        return res[0];
    }
};