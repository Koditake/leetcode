class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        std::vector<std::pair<int, int>> jobs;
        
        int n = profit.size(), 
            res = 0, 
            i = 0, 
            best = 0;
        for (int j = 0; j < n; ++j)
            jobs.push_back(make_pair(difficulty[j], profit[j]));
        
        std::sort(jobs.begin(), jobs.end());
        std::sort(worker.begin(), worker.end());
        
        for (int &ability:worker) {
            while (i < n && ability >= jobs[i].first)
                best = std::max(jobs[i++].second, best);
            res += best;
        }
        return res;
    }
};