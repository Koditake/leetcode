class Solution {
public:
    int minLength(string &s) {
        vector<char> stk;
        for (auto const &c:s) {
            if (!stk.empty()) {
                if (stk.back() == 'A' && c == 'B') {
                    stk.pop_back();
                    continue;
                }
                if (stk.back() == 'C' && c == 'D') {
                    stk.pop_back();
                    continue;
                }
            }
            stk.push_back(c);
        }
        return stk.size();
    }
};