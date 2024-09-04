class Solution {
public:
    void helper(int o, int c, string str, vector<string> &res) {
        if (o == 0 && c == 0) {
            res.push_back(str);
            return;
        }
        
        if (c > o)
            helper(o, c - 1, str + ')', res);
        
        if (o > 0)
            helper(o - 1, c, str + '(', res);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res; string str = "";
        helper(n,n,str,res);
        return res;
    }
};