class Solution {
public:
    auto switcharoo(std::vector<int> mapping, int num) -> int {
        std::string str = std::to_string(num);
        int res = 0,
            pow10 = 1;
        
        for (int i = str.size() - 1; i >= 0; --i) {
            // convert according to mapping array with order of magnitude
            int n = mapping[str[i] - '0'] * pow10;
            // add to result;
            res += n;
            // increase order of magnitude for next iteration
            pow10 *= 10;
        }
        
        return res;
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        std::map<int, std::vector<int>> map;
        
        for (auto &n:nums) {
            map[switcharoo(mapping, n)].push_back(n);
        }
        
        std::vector<int> res;
        for (auto &[map,vec]:map) {
            res.insert(res.end(), vec.begin(), vec.end());
        }
        
        return res;
    }
};