class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        std::map<int, int> nmap;
        
        for (auto &num:nums) {
            nmap[num]++;
        }
        
        int res = 0,
            need = 0;
        
        for (auto &[num,freq]:nmap) {
            res += freq*std::max(need - num,0) + freq*(freq - 1)/2;
            need = std::max(need, num) + freq;
        }
        
        return res;
    }
};