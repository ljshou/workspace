class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty()) return 0;
        const int n = prices.size();
        vector<vector<int> > f(n, vector<int>(3, 0)), g(n, vector<int>(3, 0));
        for(int i=1; i<n; ++i) {
            for(int k=1; k<=2; ++k) {
                f[i][k] = max(f[i-1][k]+prices[i]-prices[i-1], g[i][k-1]);
                g[i][k] = max(f[i][k], g[i-1][k]);
            }
        }
        return g[n-1][2];
    }
};

class Solution {
public:
    //滚动数组
    int maxProfit(vector<int> &prices) {
        if(prices.empty()) return 0;
        const int n = prices.size();
        vector<int> f(3, 0), g(3, 0);
        for(int i=1; i<n; ++i) {
            for(int k=1; k<=2; ++k) {
                f[k] = max(f[k]+prices[i]-prices[i-1], g[k-1]);
                g[k] = max(f[k], g[k]);
            }
        }
        return g[2];
    }
};
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        //滚动数组
        if(prices.size() < 2) return 0;
        const int n = prices.size();
        vector<int> local(n, 0), global(n, 0);
        for(int k=1; k<=2; ++k)
        {
            for(int i=1; i<n; ++i) {
                local[i] = max(global[i], local[i-1]+prices[i]-prices[i-1]);
                global[i] = max(local[i], global[i-1]);
            }
        }
        return global[n-1];
    }
};
