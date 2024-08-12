class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0,
            r = 0;
        
        int cvec[26] = {0};
        
        int w_l = 0,
            w_c = 0;
        
        for (r; r < s.length(); ++r) {
            ++cvec[s[r] - 'A'];
            w_c = std::max(w_c, cvec[s[r] - 'A']);
            if (r - l + 1 - w_c > k) {
                --cvec[s[l] - 'A'];
                ++l;
            }
            w_l = std::max(w_l, r - l + 1);
        }
        
        return w_l;
    }
};