class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        std::unordered_map<int, int> map;
        std::vector<int> res;
        for (auto &num:nums) {
            map[num]++;
        }
        
        std::vector<std::vector<int>> buckets (n + 1);
        
        
        for (auto &[num,cnt]:map) {
            buckets[cnt].push_back(num);
        }
        
        for (int i = n; i >= 0; i--) {
            if (res.size() >= k) {
                break;
            } 
            if (!buckets[i].empty()) {
                res.insert(res.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        
        return res;
    }
};