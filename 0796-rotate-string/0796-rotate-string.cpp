class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        
        
        for (int i = 0; i < s.size(); ++i) {
            if (s == goal) return true;
            for (int i = 0; i < s.size() - 1; ++i)
                std::swap(s[i], s[i + 1]);
        }
        
        return false;
    }
};