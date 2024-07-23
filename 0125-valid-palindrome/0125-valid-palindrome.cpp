class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size(),
            l = 0,
            r = n - 1;
        
        while (l < r) {
            if (!isalnum(s[l])) {
                ++l; continue;
            }
            
            if (!isalnum(s[r])) {
                --r; continue;
            }
            
            if (tolower(s[l]) != tolower(s[r])) 
                return false;
            else {
                ++l;
                --r;
            }
        }
        
        return true;
    }
};