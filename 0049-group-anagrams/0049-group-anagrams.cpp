class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> res;
        std::unordered_map<std::string, std::vector<std::string>> mapstr;
        
        for (auto const &str:strs) {
            auto tmp = str;
            sort(tmp.begin(),tmp.end());
            mapstr[tmp].push_back(str);
        }
        
        for (auto &[tmp,strs]:mapstr) {
            res.push_back(strs);
        }
        
        return res;
    }
};