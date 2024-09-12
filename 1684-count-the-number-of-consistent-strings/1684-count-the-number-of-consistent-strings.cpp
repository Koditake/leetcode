class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = 0;
        bool cset[26] = {false};
        for (auto const &c:allowed) cset[c - 'a'] = true;
        for (auto const &str:words) {
            bool consistent = true;
            for (auto const &c:str)
                if (!cset[c - 'a']) consistent = false;
            if (consistent) ++res;
        }
        
        return res;
    }
};