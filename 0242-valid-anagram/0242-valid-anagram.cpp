class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        int count[26];
        memset(count,0,sizeof(count));
        
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
        }
        
        for (auto c:t) {
            --count[c - 'a'];
            if (count[c - 'a'] < 0) 
                return false;
        }

        return true;
    }
};