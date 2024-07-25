class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        std::map<int, int> map;
        
        for (auto &n:nums)
            ++map[n];
        
        std::vector<int> res;
        
        for (auto &[num,freq]:map)
            for (int i = 0; i < freq; i++)
                res.push_back(num);
        
        return res;
    }
};