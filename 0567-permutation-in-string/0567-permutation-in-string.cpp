class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
        
        unordered_map<char,int> m1;
        
        for (auto const &c:s1) ++m1[c];
        for (int i = 0; i <= s2.length() - s1.length(); ++i) {
            unordered_map<char,int> m2;
            auto sstr = s2.substr(i,s1.length());
            for (auto const &c:sstr) ++m2[c];
            
            if (m1 == m2) return true;
        }
        return false;
    }
};