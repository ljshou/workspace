class Solution {
public:
    int minCut(string s) {
        if(s.size() < 2) return 0;
        const int n = s.size();
        vector<vector<bool> > g(n, vector<bool>(n, false));
        for(int i=0; i<n; ++i) g[i][i] = true;
        for(int i=n-2; i>=0; --i) {
            for(int j=i+1; j<n; ++j) {
                if(s[i] == s[j] && (j-i<2 || g[i+1][j-1])) 
                    g[i][j] = true;
            }
        }
        
        vector<int> f(n+1, INT_MAX);
        f[0] = -1;
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=i; ++j) {
                if(g[j-1][i-1])
                    f[i] = min(f[i], 1 + f[j-1]);
            }
        }
        return f[n];
    }
};
