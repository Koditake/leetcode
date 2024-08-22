class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> nmap;
        for (auto const &n:nums) ++nmap[n];
        
        vector<vector<int>> vect (nums.size() + 1);
        
        for (auto &[num,freq]:nmap) {
            vect[freq].push_back(num);
        }
        
        vector<int> res;
        for (int i = vect.size() - 1; i >= 0; --i) {
            if (res.size() >= k) break;
            if (!vect[i].empty()) {
                res.insert(res.end(), vect[i].begin(), vect[i].end());
            }
        }
        return res;
    }
};