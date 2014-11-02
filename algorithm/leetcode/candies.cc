class Solution {
public:
    int candy(vector<int> &ratings) {
        const int n = ratings.size();
        if(n == 0) return 0;
        vector<int> f(n, 1);
        for(int i=1; i<n; ++i) {
            if(ratings[i] > ratings[i-1]) f[i] = max(f[i-1]+1, f[i]);
        } 
        for(int i=n-2; i>=0; --i) {
            if(ratings[i] > ratings[i+1]) f[i] = max(f[i+1]+1, f[i]);
        }
        return accumulate(f.begin(), f.end(), 0);
    }
};
