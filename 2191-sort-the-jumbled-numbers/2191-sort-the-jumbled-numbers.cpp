class Solution {
public:
    inline auto switcharoo(vector<int>& mapping, int num) -> int {
        if (num < 10)
            return mapping[num];
        
        int res = 0,
            pow10 = 1;
        
        while (num > 0) {
            res += mapping[num%10] * pow10;
            pow10 *= 10, num /= 10;
        }
        
        return res;
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        std::vector<pair<int, int>> vec_p;

        for (int i = 0; i < nums.size(); ++i) {
            // Push a pair consisting of mapped value and original value's index.
            vec_p.push_back({switcharoo(mapping, nums[i]), i});
        }

        // Sort the array in non-decreasing order by the first value (default).
        std::sort(vec_p.begin(), vec_p.end());
        std::vector<int> res;
        
        for (auto &[p1,p2]:vec_p)
            res.push_back(nums[p2]);
        
        return res;
    }
};