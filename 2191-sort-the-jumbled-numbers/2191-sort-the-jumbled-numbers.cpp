class Solution {
public:
    inline auto switcharoo(vector<int>& mapping, int num, int res = 0, int pow10 = 1) -> int {
        if (num < 10)
            return mapping[num];
        
        while (num > 0) {
            res += mapping[num%10] * pow10;
            pow10 *= 10, num /= 10;
        }
        
        return res;
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        std::vector<pair<int, int>> storePairs;

        for (int i = 0; i < nums.size(); ++i) {
            // Store the mapped value.
            // int mappedValue = switcharoo(mapping, nums[i]);
            // Push a pair consisting of mapped value and original value's index.
            storePairs.push_back({switcharoo(mapping, nums[i]), i});
        }

        // Sort the array in non-decreasing order by the first value (default).
        std::sort(storePairs.begin(), storePairs.end());
        std::vector<int> answer;
        
        for (auto &[p1,p2]:storePairs)
            answer.push_back(nums[p2]);
        
        return answer;
    }
};