class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> cset;
        int res = 0;
        int l = 0, r = 0, n = s.length();
        for (r; r < n; ++r) {
            if (cset.contains(s[r])) {
                while (cset.contains(s[r])) {
                    cset.erase(s[l]);
                    ++l;
                }
            } else {
                res = max(res, r - l + 1);    
            }
            cset.insert(s[r]);
        }
        
        return res;
    }
};