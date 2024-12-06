class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0,
            min_price = INT_MAX;
        
        for (auto const &p:prices) {
            max_profit = max(max_profit,p - min_price);
            min_price = min(p,min_price);
        }
        
        return max_profit;
    }
};