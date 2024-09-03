class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.size(), res = 0;
        vector<bool> cmap (256, false);
        for (r; r < n; ++r) {
            while (cmap[s[r]] == true) {
                cmap[s[l]] = false;
                ++l;
            }
            cmap[s[r]] = true;
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};