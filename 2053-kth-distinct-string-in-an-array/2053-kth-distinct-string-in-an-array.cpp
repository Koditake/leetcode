class Solution {
public:
    auto find_pos(vector<tuple<string,int>> &vtup, string &str, int pos = 0) -> int {
        for (auto &[s,c]:vtup)
            if (s == str) return pos;
            else ++pos;
        return -1;
    }
    
    string kthDistinct(vector<string>& arr, int k) {
        std::vector<std::tuple<string,int>> vtup;
        
        for (auto &s:arr) {
            int pos = find_pos(vtup,s);
            if (pos == -1) {
                vtup.push_back({s,1});
            } else {
                std::get<1>(vtup[pos]) += 1;
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