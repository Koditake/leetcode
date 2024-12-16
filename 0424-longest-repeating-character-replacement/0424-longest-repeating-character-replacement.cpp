class Solution {
public:
    int characterReplacement(string s, int k) {
        //use an int array
        std::array<int,26> cmap;
        
        int l = 0, r = 0, m = 0, res = 0;
        
        for (r; r < s.size(); ++r) {
            ++cmap[s[r] - 'A'];
            //Find if current character is the longest character in our window
            m = max(m, cmap[s[r] - 'A']);
            // Find if replace the longest character in our window m
            // still within our budget of k chacters
            while (r - l + 1 - m > k) {
                --cmap[s[l] - 'A'];
                ++l;
            }
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};