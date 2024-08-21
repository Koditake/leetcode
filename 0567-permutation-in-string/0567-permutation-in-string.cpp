class Solution {
public:
    bool checkInclusion(string &s1, string &s2) {
        if (s1.length() > s2.length()) return false;
        
        unordered_map<char, int> map1;
        for (auto const &c:s1) ++map1[c];
        
        for (int i = 0; i <= s2.length() - s1.length(); ++i) {
            unordered_map<char, int> map2;
            auto s2b = s2.substr(i,s1.length());
            for (auto const &c:s2b) ++map2[c];
            if (map1 == map2) return true;
        }
        
        return false;
    }
};