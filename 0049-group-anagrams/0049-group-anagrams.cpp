class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> m;

        for (string &str:strs) {
            std::string temp = str;
            std::sort(temp.begin(),temp.end());
            m[temp].push_back(str);
        }

        std::vector<std::vector<std::string>> res;

        for (auto &[id,strs]:m) {
            res.push_back(strs);
        }

        return res;
    }
};