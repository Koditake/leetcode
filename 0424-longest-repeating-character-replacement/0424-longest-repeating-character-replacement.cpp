class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> cmap;
        int l = 0, r = 0, n = s.length(), res = 0, c = 0;
        for (r; r < n; ++r) {
            ++cmap[s[r] - 'A'];
            c = max(c,cmap[s[r] - 'A']);
            while (r - l + 1 - c > k) {
                --cmap[s[l] - 'A'];
                ++l;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};