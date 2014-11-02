class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        const int m = s1.size(), n = s3.size();
        vector<vector<bool> > f(m+1, vector<bool>(n+1, false));
        f[0][0] = true;
        for(int i=1; i<=s2.size(); ++i)  f[0][i] = f[0][i-1] && (s2[i-1] == s3[i-1]);
        for(int i=1; i<=m; ++i) {
            for(int j=1; j<=n; ++j) {
                f[i][j] = (s1[i-1] == s3[j-1] && f[i-1][j-1])
                        || ((j > i) && s2[j-i-1] == s3[j-1] && f[i][j-1]);
            }
        }
        return f[m][n];
    }
};
