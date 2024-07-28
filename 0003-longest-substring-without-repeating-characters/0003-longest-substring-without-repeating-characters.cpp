class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0,
            l = 0,
            r = 0;
        
        int vec_c[256] = {0};
        
        for (r; r < s.size(); ++r) {
            // While the current character is already in the window
            while (vec_c[s[r]] > 0) {
                // Slide the left pointer of the window
                --vec_c[s[l]];
                ++l;
            }

            // Update the maximum length of substring
            res = max(res, r - l + 1);

            // Include the current character in the window
            ++vec_c[s[r]];
        }
        
        return res;
    }
};