class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, n = s.size(), res = 0, cmax = 0;
        //unordered_map<char,int> cmap;
        vector<int> cmap (26,0);
        for (r; r < n; ++r) {
            ++cmap[s[r] - 'A'];
            cmax = max(cmap[s[r] - 'A'], cmax);
            while (r - l + 1 - cmax > k) {
                --cmap[s[l] - 'A'];
                ++l;
            }
            
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};