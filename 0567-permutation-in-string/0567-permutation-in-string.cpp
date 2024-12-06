class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
        
        vector<int> m1 (26,0),
                    m2 (26,0);
        
        for (int i = 0; i < s1.length(); ++i) {
            ++m1[s1[i] - 'a'];
            ++m2[s2[i] - 'a'];
        }
        
        if (m1 == m2) return true;
        
        for (int i = s1.length(); i < s2.length(); ++i) {
            --m2[s2[i - s1.length()] - 'a'];        
            ++m2[s2[i] - 'a'];
            
            if (m1 == m2) return true;
        }   
        
        return false;
    }
};