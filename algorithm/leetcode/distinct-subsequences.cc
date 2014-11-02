class Solution {
public:
    int numDistinct(string S, string T) {
        if(S.empty() || T.empty()) return 0;
        const int m = S.size(), n = T.size();
        vector<vector<int> > f(m+1, vector<int>(n+1, 0));
        for(int i=0; i<=m; ++i) f[i][0] = 1; //很重要，最关键
        for(int i=1; i<=m; ++i) {
            for(int j=1; j<=n; ++j) {
                f[i][j] = f[i-1][j] + ((S[i-1] == T[j-1]) ? f[i-1][j-1] : 0); 
            }
        }
        return f[m][n];
    }
};
