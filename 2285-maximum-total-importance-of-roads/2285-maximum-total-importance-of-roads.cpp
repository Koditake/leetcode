class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        std::vector<int> edgeCount(n,0);			
        //For counting the number of edges the given node is part of
        for(int i = 0; i < roads.size(); i++) {
            edgeCount[roads[i][0]]++;
            edgeCount[roads[i][1]]++;
        }
        std::sort(edgeCount.begin(), edgeCount.end());
        long long res = 0;
        for(int i = 0; i < n; i++)
        {
            res += (long long)edgeCount[i]*(i+1);
        }
        return res;
    }
};