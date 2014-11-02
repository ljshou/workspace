class Solution {
public:
    int numTrees(int n) {
        if(n == 0) return 0;
        vector<int> f(n+1, 0);
        f[0] = 1;
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=i; ++j) {
                f[i] += f[j-1] * f[i-j];
            }
        }
        return f[n];
    }
};
