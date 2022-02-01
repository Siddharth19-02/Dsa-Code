class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        int n = prices.size();
        int max_profit = 0;
        int min_till_now = INT_MAX;
        
        for(int i=1;i<n;i++)
        {
            min_till_now = min(min_till_now,prices[i-1]);
            max_profit = max(max_profit,prices[i]-min_till_now);
        }
        
        return max_profit;
    }
};
