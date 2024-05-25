class Solution {
public:
    void solve(std::string s, std::vector<std::string>& res, std::unordered_set<std::string>& st, std::vector<std::string>&temp){
        if(s.length() == 0){
            std::string str = "";
            for(auto it:temp){
                str += it + " ";
            }
            str.pop_back();
            res.push_back(str);
            return;
        }
        for(int i = 0; i < s.length(); i++){
            if(st.count(s.substr(0, i+1))){
                temp.push_back(s.substr(0, i+1));
                solve(s.substr(i+1), res, st, temp);
                temp.pop_back();
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        std::vector<string>res, temp;
        std::unordered_set<string>st(wordDict.begin(), wordDict.end());
        
        solve(s, res, st, temp);
        return res;
    }
};