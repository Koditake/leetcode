class Solution {
public:
    char repeatedCharacter(string s) {
        std::set<char> set_s;
        char res;
        
        for (auto &c:s) {
            if (!set_s.contains(c)) {
                set_s.insert(c);
            } else {
                return res = c;
            }
        }
        
        return res;
    }
};