class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> cmap;
        
        int l = 0, r = 0, m = 0, res = 0;
        
        for (r; r < s.size(); ++r) {
            ++cmap[s[r]];
            //Find if current character is the longest character in our window
            m = max(m, cmap[s[r]]);
            // Find if replace the longest character in our window m
            // still within our budget of k chacters
            while (r - l + 1 - m > k) {
                --cmap[s[l]];
                ++l;
            }
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};