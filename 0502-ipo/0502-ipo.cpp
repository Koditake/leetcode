class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        std::vector <std::pair <int,int>> arr;
        
        for (int i = 0; i<profits.size(); i++) 
            arr.push_back({capital[i],profits[i]});
        std::sort(arr.begin(),arr.end());
        
        std::priority_queue <int> q;
        int ans = 0, i=0;
        while(i < arr.size() and k) {
            if (w >= arr[i].first) 
                q.push(arr[i++].second);
            else {
				// This condition will check if we had enough capital to choose any project or not. If not, we directly return the current capital.
                if (q.empty()) 
                    return w;
                
                w += q.top();
                q.pop();
                k--;
            }
        }
        
		// Here, we check if we could still choose some projects
        while (k-- and !q.empty()) {
            w += q.top();
            q.pop();
        }
        return w;
    }
};