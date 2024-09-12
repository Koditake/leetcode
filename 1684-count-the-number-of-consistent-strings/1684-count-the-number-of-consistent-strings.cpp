class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = 0;
        bool cset[26] = {false};
        for (auto const &c:allowed) cset[c - 'a'] = true;
        for (auto const &str:words) {
            int is_const = true;
            for (auto const &c:str)
                if (!cset[c - 'a']) is_const = false;
            if (is_const) ++res;
        }
        
        return res;
    }
};