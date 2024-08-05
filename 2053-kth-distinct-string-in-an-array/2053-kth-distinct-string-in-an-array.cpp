class Solution {
public:
    auto find_pos(vector<tuple<string,int>> &vtup, string &str, int pos = 0) -> int {
        for (auto &[s,c]:vtup)
            if (s == str) return pos;
            else ++pos;
        return -1;
    }
    
    string kthDistinct(vector<string>& arr, int k) {
        std::unordered_set<string> uset;
        std::vector<std::tuple<string,int>> vtup;
        
        for (auto &s:arr) {
            if (!uset.contains(s)) {
                uset.insert(s);
                vtup.push_back({s,1});
            } else {
                std::get<1>(vtup[find_pos(vtup,s)]) += 1;
            }
        }
        
        for (auto const &[s,c]:vtup) {
            if (c == 1) {
                if (k == 1) return s;
                else --k;
            }
        }
        
        return "";
    }
};