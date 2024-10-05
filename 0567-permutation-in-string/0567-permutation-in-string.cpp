class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(),
            n2 = s2.size();
        
        unordered_map<char,int> m1;
        for (auto const &c:s1) ++m1[c];
        
        for (int i = 0; i <= n2 - n1; ++i) {
            auto str = s2.substr(i,n1);
            unordered_map<char,int> m2;
            for (auto const &c:str) ++m2[c];
            if (m1 == m2) return true;
        }
        
        return false;
    }
};