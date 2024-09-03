class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map (256,0);
        int n = s.length(), l = 0, r = 0, res = 0;
        for (r; r < n; ++r) {
                while (map[s[r]] > 0) {
                    --map[s[l]];
                    ++l;
                }
            ++map[s[r]];
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};