class Solution {
public:
    auto switcharoo(std::vector<int> mapping, int num) -> int {
        int res = 0,
            pow10 = 1;

        if (num == 0)
            return mapping[num];
        
        while (num > 0) {
            res += mapping[(num % 10)] * pow10;
            pow10 *= 10;
            num /= 10;
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