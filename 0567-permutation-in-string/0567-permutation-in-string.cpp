class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int  
            n1 = s1.size(), 
            n2 = s2.size();
        
        if (n1 > n2) return false;
        
        unordered_map<char,int> m1;
        
        for (auto const &c:s1) ++m1[c];
        
        for (int i = 0; i <= n2 - n1; ++i) {
            unordered_map<char,int> m2;
            auto str = s2.substr(i, n1);
            for (auto const &c:str) ++m2[c];
            if (m2 == m1) 
                return true;
        }
        
        return false;
    }
};