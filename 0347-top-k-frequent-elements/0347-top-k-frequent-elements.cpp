class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> nmap;
        for (auto const &n:nums) ++nmap[n];
        int n = nmap.size();
        priority_queue<pair<int,int>> pq;
        vector<int> res;
        for (auto const &[num,freq]:nmap) {
            pq.push({freq,num});
            if (pq.size() >= n - k + 1) {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};