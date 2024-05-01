class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> res;
        std::unordered_map<std::string,std::vector<std::string>> strmap;
        
        for (auto &str:strs) {
            auto temp = str;
            sort(temp.begin(),temp.end());
            strmap[temp].push_back(str);
        }
        
        for (auto &[templ, str]:strmap) {
            res.push_back(str);
        }
        
        return res;
    }
};