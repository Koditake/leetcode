class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> cset;
        int l = 0, res = 0;
        for (int r = 0; r < s.size(); ++r) {
            while (cset.contains(s[r])) {
                cset.erase(s[l]);
                ++l;
            }
            cset.insert(s[r]);
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};