class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        std::map<int, std::string, std::greater<int>> map;
        
        for (int i = 0; i < n; i++) {
            map[heights[i]] = names[i];
        }
        
        std::vector<std::string> res;
        
        for (auto &[height,name]:map)
            res.push_back(name);
        
        return res;
    }
};