class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0,
            r = 0;
        
        int w_c = 0,
            w_l = 0;
        
        std::unordered_map<int,int> cmap;
        
        for (r; r < s.length(); ++r) {
            ++cmap[s[r]];
            w_c = std::max(w_c, cmap[s[r]]);
            if (r - l + 1 - w_c > k) {
                --cmap[s[l]];
                ++l;
            }
            w_l = std::max(w_l, r - l + 1);
        }
        
        return w_l;
    }
};