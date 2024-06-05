class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        std::vector<int> cnt(26, INT_MAX);
        std::vector<std::string> res;
        for (auto w:words) {
            std::vector<int> cnt1(26, 0);
            for (auto c:w) 
                ++cnt1[c - 'a'];
            for (auto i = 0; i < 26; ++i) 
                cnt[i] = min(cnt[i], cnt1[i]);
        }
        
        for (auto i = 0; i < 26; ++i)
            for (auto j = 0; j < cnt[i]; ++j) 
                res.push_back(string(1, i + 'a'));
        
        return res;
    }
};