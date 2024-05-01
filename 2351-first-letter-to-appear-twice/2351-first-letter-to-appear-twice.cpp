class Solution {
public:
    char repeatedCharacter(string s) {
        int s_set[26] = {0};
        
        for (auto &c:s) {
            if (s_set[c - 'a']) 
                return c;
            else
                ++s_set[c - 'a'];
        }
        
        return ' ';
    }
};