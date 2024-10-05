class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(),
            n2 = s2.size();
        
        vector<int> m1 (26,0);
        
        for (auto const &c:s1) ++m1[c - 'a'];
        
        for (int i = 0; i <= n2 - n1; ++i) {
            vector<int> m2 (26,0);
            auto st = s2.substr(i, n1);
            for (auto const &c:st) ++m2[c - 'a'];
            if (m1 == m2) return true;
        }
        
        return false;
    }
};