class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty()) return 0;
        int profit(0);
        const int n = prices.size();
        vector<int> f(prices.begin(), prices.end());
        for(int i=n-2; i>=0; --i) f[i] = max(f[i+1], prices[i]);
        
        for(int i=0; i<n; ++i) profit = max(profit, f[i] - prices[i]);
        return profit;
    }
};
