class Solution {
public:
    bool checkInclusion(string &s1, string &s2) {
        int n1 = s1.size(),
            n2 = s2.size();
        
        if (n1 > n2) return false;
        
        vector<int> m1 (26,0), m2 (26,0);
        int cnt = 0;
        for (int i = 0; i < n1; ++i) {
            ++m1[s1[i] - 'a'];
            ++m2[s2[i] - 'a'];
        }
        
        for (int i = 0; i < 26; ++i) if (m1[i] == m2[i]) ++cnt;
        
        
        for (int i = n1; i < n2; ++i) {
            if (cnt == 26) return true;
            
            int r = s2[i] - 'a',
                l = s2[i - n1] - 'a';    
            
            ++m2[r];
            if (m2[r] == m1[r]) ++cnt; 
            else if (m2[r] == m1[r] + 1) --cnt;
            
            --m2[l];
            if (m2[l] == m1[l]) ++cnt;
            else if (m2[l] == m1[l] - 1) --cnt;
        }
        
        return cnt == 26;
    }
};