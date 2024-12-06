class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //vector<int> cset (256,0);
        int cset [256] = {0};
        int l = 0, res = 0;
        for (int r = 0; r < s.size(); ++r) {
            while (cset[s[r]]) {
                --cset[s[l]];
                ++l;
            }
            ++cset[s[r]];
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};