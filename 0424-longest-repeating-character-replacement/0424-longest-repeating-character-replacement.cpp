class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0,
            r = 0,
            m_l = 0,
            m_w = 0;
        
        std::unordered_map<int,int> map;
        
        for (r; r < s.size(); ++r) {
            ++map[s[r]];
            m_w = max(m_w, map[s[r]]);
            if (r - l + 1 - m_w > k) {
                --map[s[l]];
                ++l;
            }
            
            m_l = max(m_l, r - l + 1);
        }
        
        return m_l;
    }
};