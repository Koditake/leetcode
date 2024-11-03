class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> cset;
        
        int l = 0, r = 0, n = s.length(), res = 0;
        
        for (r; r < n; ++r) {
            while (cset.find(s[r]) != cset.end()) {
                
                cset.erase(s[l]);
                ++l;
            } 
            cset.insert(s[r]);
            res = max(res, r - l + 1);
        }
                
        return res;
    }
};