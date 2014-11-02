class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty()) return 0;
        int profit(0);
        for(int i=0; i<prices.size()-1; ++i) 
            profit += (prices[i+1] - prices[i] > 0) ? (prices[i+1] - prices[i]) : 0;
        return profit;
    }
};
