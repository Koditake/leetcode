impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let (mut max_profit, mut min_price) = (0, 10000);
        for price in prices {
            max_profit = max_profit.max(price - min_price);
            min_price = min_price.min(price);
        }
        
        max_profit
    }
}