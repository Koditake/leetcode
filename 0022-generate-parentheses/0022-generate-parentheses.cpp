class Solution {
public:
    auto helper(std::string str, int o, int c, vector<string> &res) -> void {
        if (!o && !c) {
            res.push_back(str);
            return;
        }
        
        if (o < c) helper(str + ")", o, c - 1, res);
        if (o >= 0) helper(str + "(", o - 1, c, res);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper("", n, n, res);
        return res;
    }
};