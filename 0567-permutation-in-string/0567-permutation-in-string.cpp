class Solution {
public:
    bool checkInclusion(string &s1, string &s2) {
        int n1 = s1.size(),
            n2 = s2.size();
        
        if (n1 > n2) return false;
        
        vector<int> map1 (26,0);
        for (auto const &c:s1) ++map1[c - 'a'];
        for (int i = 0; i <= n2 - n1; ++i) {
            vector<int> map2 (26,0); 
            auto s2b = s2.substr(i, n1);
            for (auto const &c:s2b) ++map2[c - 'a'];
            if (map1 == map2) return true;
        }
        
        return false;
    }
};