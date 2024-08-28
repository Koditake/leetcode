class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.size(),
            np = p.size();
        
        if (np > ns) return {};
        
        vector<int> res, ms (26,0), mp(26,0);
        
        for (int i = 0; i < np; ++i) {
            ++mp[p[i] - 'a'];
            ++ms[s[i] - 'a'];
        }
        
        if (mp == ms) res.push_back(0);
        
        int r = np;
        for (r; r < ns; ++r) {
            ++ms[s[r] - 'a'];
            --ms[s[r - np] - 'a'];
            if (ms == mp) res.push_back(r - np + 1);
        }
        
        return res;
    }
};