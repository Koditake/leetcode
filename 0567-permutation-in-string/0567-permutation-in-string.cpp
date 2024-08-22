class Solution {
public:
    bool checkInclusion(string &s1, string &s2) {
        int n1 = s1.size(),
            n2 = s2.size();
        
        if (n1 > n2) return false;
        
        vector<int> vec1 (26,0);
        
        for (auto const &c:s1) ++vec1[c - 'a'];
        
        int
            r = 0;
        
        for (r; r <= n2 - n1; ++r) {
            auto s2b = s2.substr(r,n1);
            vector<int> tmp (26,0);
            for (auto const &c:s2b) ++tmp[c - 'a'];
            if (vec1 == tmp) return true;
        }
        return false;
    }
};