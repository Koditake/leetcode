class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {  
        if (nums.size() == k) return nums;
        
        unordered_map<int,int> nmap;
        for (auto const &n:nums) ++nmap[n];
        
        priority_queue<pair<int,int>> pq; vector<int> res;
        for (auto const &[num,freq]:nmap) {
            pq.push({freq,num});
            if (pq.size() > nmap.size() - k) {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};