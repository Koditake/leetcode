class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        std::vector<int> res;
        for (auto &num:nums) {
            map[num]++;
        }
        
        std::priority_queue<std::pair<int,int>> p_queue;
        
        for (auto &[num,cnt]:map) {
            p_queue.push({cnt,num});
            
            if (p_queue.size() > map.size() - k) {
                res.push_back(p_queue.top().second);
                p_queue.pop();
            }
        }
        
        return res;
    }
};