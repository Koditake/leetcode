class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for (auto &str:details) {
            if ((str[11] - '0')*10 + (str[12] - '0') > 60)
                ++res;
        }
        
        return res;
    }
};