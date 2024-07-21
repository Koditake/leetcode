class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> res;
        
        for (auto n:nums) {
            res[n]++;
        }
        
        for (auto &[num,freq]:res) {
            if (freq == 1) {
                return num;
            }
        }
        
        return -1;
    }
};