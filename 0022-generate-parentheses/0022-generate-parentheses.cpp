class Solution {
    void generator(int o, int c, string seed, vector<string> &res) {
        if (o == 0 && c == 0) {
            res.push_back(seed);
            return;
        }
        
        if (o < c)
            generator(o, c - 1, seed + ')', res);
        if (o > 0)
            generator(o - 1, c, seed + '(', res);
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generator(n,n,"",res);
        return res;
    }
};