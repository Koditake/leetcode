class Solution {
public:
    auto switcharoo(vector<int>& mapping, int num) -> int {
        if (num < 10)
            return mapping[num];
        
        int res = 0,
            pow10 = 1;
        
        while (num > 0) {
            res += mapping[num%10] * pow10;
            pow10 *= 10;
            num /= 10;
        }
        
        return res;
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        std::vector<pair<int, int>> storePairs;

        for (int i = 0; i < nums.size(); ++i) {
            // Store the mapped value.
            int mappedValue = switcharoo(mapping, nums[i]);
            // Push a pair consisting of mapped value and original value's index.
            storePairs.push_back({mappedValue, i});
        }

        // Sort the array in non-decreasing order by the first value (default).
        sort(storePairs.begin(), storePairs.end());
        vector<int> answer;
        for (auto pair : storePairs) {
            answer.push_back(nums[pair.second]);
        }
        return answer;
    }
};