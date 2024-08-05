class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        std::unordered_map<string, int> mstr;
        for (auto const &s:arr) ++mstr[s];
        
        for (auto const &s:arr) {
            if (mstr[s] == 1) {
                if (k == 1) return s;
                else --k;
            }
        }
        
        return "";
    }
};