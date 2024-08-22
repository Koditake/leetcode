class Solution {
public:
    bool checkInclusion(string &s1, string &s2) {
        int n1 = s1.size(),
            n2 = s2.size();
        
        if (n1 > n2) return false;
        
        vector<int> vec1 (26,0), 
                    vec2 (26,0);
        
        for (int i = 0; i < n1; ++i) {
            ++vec1[s1[i] - 'a'];
            ++vec2[s2[i] - 'a'];
        }
        
        if (vec1 == vec2) return true;
        
        int r = 0;
        
        for (r = n1; r < n2; ++r) {
            --vec2[s2[r - n1] - 'a'];
            ++vec2[s2[r] - 'a'];
            if (vec2 == vec1) return true;
        }
        return false;
    }
};