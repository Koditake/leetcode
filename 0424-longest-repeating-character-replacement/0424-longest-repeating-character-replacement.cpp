class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int l = 0, r = 0, res = 0, cmax = 0;
        for (r; r < s.length(); ++r) {
            ++mp[s[r] - 'A'];
            cmax = max(mp[s[r] - 'A'], cmax);
            while (r - l + 1 - cmax > k) {
                --mp[s[l] - 'A'];
                ++l;
            }
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};