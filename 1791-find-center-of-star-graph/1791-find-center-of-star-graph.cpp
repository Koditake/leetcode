class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        std::unordered_map<int, int> starchart;
        std::vector<int> res (2,0);
        for (auto &edge:edges) {
            ++starchart[edge[0]];
            ++starchart[edge[1]];    
        }
        
        for (auto &[node, freq]:starchart) {
            if (freq > res[1]) {
                res[0] = node;
                res[1] = freq;
            }
        }
        
        return res[0];
    }
};