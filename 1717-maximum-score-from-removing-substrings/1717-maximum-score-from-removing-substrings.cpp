class Solution {
private:
    auto remove(std::string &s, std::string r, int x) -> int {
        int i = 0, 
            res = 0; 
        for (int j = 0; j < s.size(); ++j) {
            s[i++] = s[j];
            if (i > 1 && s[i - 2] == r[0] && s[i - 1] == r[1]) i -= 2, res += x; 
        }
    
        s.resize(i);
        return res;
    }
    
public:
    int maximumGain(string s, int x, int y) {
        std::string a = "ab", 
                    b = "ba";
        if (x < y) 
                swap(a, b), swap(x, y);
        
        return remove(s, a, x) + remove(s, b, y);
    }
};