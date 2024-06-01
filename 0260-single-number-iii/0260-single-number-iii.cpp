class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        std::unordered_map<int, int> freq;
        
        for (auto &num: nums) 
            ++freq[num];
        
        std::vector<int> res;
        
        for (auto &[x, f]: freq)
            if (f == 1) {
                res.push_back(x);
                if (res.size() == 2)
                    return res;
            }
        return res;
    }
};